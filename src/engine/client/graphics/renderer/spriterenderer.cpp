#include <iostream>

#include "spriterenderer.h"
#include "../sprite.h"

void SpriteRenderer::SetBuffer(void *pBuffer, size_t size)
{
	m_pBuffer = pBuffer;
	m_Capacity = size / ELEMENT_SIZE;

	std::cout << "init SpriteRenderer with Capacity = " << m_Capacity << " and " << size - m_Capacity * ELEMENT_SIZE << " Bytes unused." << std::endl;
}

void SpriteRenderer::Flush()
{
	m_Size = 0;
	m_pVertexPos = m_pVertices;
	m_pUVPos = m_pUVs;
}

void SpriteRenderer::Draw(const Sprite &s)
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
