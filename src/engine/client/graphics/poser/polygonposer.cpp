#include <iostream>

#include <engine/log.h>
#include "polygonposer.h"
#include "../sprite.h"

PolygonPoser::PolygonPoser(Pipeline *pPipeline)
	: Poser(pPipeline)
{}

PolygonPoser::~PolygonPoser()
{}

void PolygonPoser::SetBuffer(void *pBuffer, size_t size)
{
	m_pBuffer = pBuffer;
	m_CapacityBytes = size;
	m_Capacity = size / ELEMENT_SIZE;

	Log.Debug() << "init PolygonPoser with Capacity = " << m_Capacity << " and " << size - m_Capacity * ELEMENT_SIZE << " Bytes unused.";
}

void PolygonPoser::Flush()
{
	m_Size = 0;
	m_pVertexPos = m_pVertices;
	m_pUVPos = m_pUVs;

	m_pPipeline->MakeCurrent();
	//glUniform2fv();
}

void PolygonPoser::Draw(const Sprite &s, const Vec2 &pos)
{
	if(m_Size == m_Capacity)
		Flush();

	//*m_pVertexPos++ = s.m_Vec[0];
	//*m_pVertexPos++ = s.m_Vec[1];
	//*m_pVertexPos++ = s.m_Vec[2];
	//*m_pVertexPos++ = s.m_Vec[3];
	//*m_pUVPos++ s.m_UV[0];
	//*m_pUVPos++ s.m_UV[1];
	//*m_pUVPos++ s.m_UV[2];
	//*m_pUVPos++ s.m_UV[3];

	m_Size++;
}
