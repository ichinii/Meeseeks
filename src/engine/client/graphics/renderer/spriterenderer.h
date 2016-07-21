#ifndef ENGINE_SPRITERENDERER_H
#define ENGINE_SPRITERENDERER_H

//#include <cstddef>

#include <util/vec.h>

class Sprite;

class SpriteRenderer {
private:
	static const size_t VERTEX_SIZE = sizeof(Vec2);
	static const size_t UV_SIZE = sizeof(Vec2);
	static const size_t VERTICES_PER_ELEMENT = 4;
	static const size_t ELEMENT_SIZE = VERTICES_PER_ELEMENT * (VERTEX_SIZE + UV_SIZE);
	void *m_pBuffer;
	Vec2 *m_pVertices;
	Vec2 *m_pUVs;
	Vec2 *m_pVertexPos;
	Vec2 *m_pUVPos;
	size_t m_Size;
	size_t m_Capacity;

	//Pipeline m_Pipeline;

public:
	void SetBuffer(void *pBuffer, size_t size);
	//void SetPipeline();

	void Flush();
	void Draw(const Sprite &s);
	void Draw(Vec2 v0, Vec2 v1, Vec2 v2, Vec2 v3);
	void Draw(Vec2 pos, Vec2 size);
};

#endif
