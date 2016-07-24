#include "polygonposer.h"
#include <GL/glew.h>
#include <engine/log.h>
#include "../sprite.h"

PolygonPoser::PolygonPoser(Pipeline *pPipeline)
	: Poser(pPipeline)
{
	m_Size = 0;

	pPipeline->MakeCurrent();

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VertexGLBuffer);
	glGenBuffers(1, &m_UVGLBuffer);

	glBindVertexArray(m_VAO);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexGLBuffer);
	glVertexAttribPointer(
		0,
		4,
		GL_FLOAT,
		GL_FALSE,
		VERTEX_SIZE,
		nullptr
	);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_UVGLBuffer);
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		UV_SIZE,
		nullptr
	);
	glBindVertexArray(0);
}

PolygonPoser::~PolygonPoser()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VertexGLBuffer);
	glDeleteBuffers(1, &m_UVGLBuffer);
}

void PolygonPoser::SetBuffer(void *pBuffer, size_t size)
{
	if(m_Size > 0)
		Flush();

	m_Size = 0;
	m_pBuffer = pBuffer;
	m_CapacityBytes = size;
	m_Capacity = size / ELEMENT_SIZE;

	m_pVertices = static_cast<decltype(m_pVertices)>(m_pBuffer);
	m_pUVs = m_pVertices + m_Capacity;
	m_pVertexPos = m_pVertices;
	m_pUVPos = m_pUVs;

	Log.Debug() << "Init PolygonPoser with capacity = " << m_Capacity << " and " << size - m_Capacity * ELEMENT_SIZE << " bytes unused.";
}

void PolygonPoser::Flush()
{
	m_pPipeline->MakeCurrent();

	// TODO: only allocate new buffer in SetBuffer
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexGLBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_Capacity * VERTEX_SIZE, m_pVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, m_UVGLBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_Capacity * UV_SIZE, m_pUVs, GL_STATIC_DRAW);

	glBindVertexArray(m_VAO);
	glDrawArrays(GL_QUADS, 0, m_Size * VERTICES_PER_ELEMENT);
	glBindVertexArray(0);

	m_Size = 0;
	m_pVertexPos = m_pVertices;
	m_pUVPos = m_pUVs;
}

void PolygonPoser::Draw(const Sprite &s, const Vec2 &pos)
{
	if(m_Size == m_Capacity)
		Flush();

	*m_pVertexPos++ = s.m_Pos[0];
	*m_pVertexPos++ = s.m_Pos[1];
	*m_pVertexPos++ = s.m_Pos[2];
	*m_pVertexPos++ = s.m_Pos[3];
	*m_pUVPos++ = s.m_UV[0];
	*m_pUVPos++ = s.m_UV[1];
	*m_pUVPos++ = s.m_UV[2];
	*m_pUVPos++ = s.m_UV[3];

	m_Size++;
}
