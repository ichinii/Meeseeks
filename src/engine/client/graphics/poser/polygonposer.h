#ifndef ENGINE_POLYGON_POSER_H
#define ENGINE_POLYGON_POSER_H

#include <util/vec.h>
#include "../poser.h"

class Sprite;

class PolygonPoser : public Poser {
private:
	static const size_t VERTEX_SIZE = sizeof(Vec2);
	static const size_t UV_SIZE = sizeof(Vec2);
	static const size_t VERTICES_PER_ELEMENT = 4;
	static const size_t ELEMENT_SIZE = VERTICES_PER_ELEMENT * (VERTEX_SIZE + UV_SIZE);
	Vec2 *m_pVertices;
	Vec2 *m_pUVs;
	Vec2 *m_pVertexPos;
	Vec2 *m_pUVPos;
	size_t m_Size;
	size_t m_Capacity;

	GLuint m_VertexGLBuffer;
	GLuint m_UVGLBuffer;
	GLuint m_VAO;

public:
	PolygonPoser(Pipeline *pPipeline);
	~PolygonPoser();

	void SetBuffer(void *pBuffer, size_t size);
	void Flush();
	void Draw(const Sprite &s, const Vec2 &pos);
	//void Draw(Vec2 v0, Vec2 v1, Vec2 v2, Vec2 v3);
	//void Draw(Vec2 pos, Vec2 size);
};

#endif
