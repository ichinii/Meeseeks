#ifndef ENGINE_GRAPHICS_DEFAULT_H
#define ENGINE_GRAPHICS_DEFAULT_H

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <util/vec.h>
#include "../graphics.h"
#include "poser/polygonposer.h"
#include "pipeline.h"

class Sprite;

class Graphics_Default : public Graphics {
private:
	sf::Window *m_pWindow;

	Pipeline *m_pPolygonPipeline;
	PolygonPoser *m_pPolygonPoser;

	static const size_t BUFFER_SIZE = 1024 * 8;
	void *m_pBuffer;

public:
	Graphics_Default();
	virtual ~Graphics_Default();

	virtual bool Init(int argc, char *argv[]);
	virtual bool Shutdown();
	virtual void Clear();
	virtual void Display();
	virtual void Flush();
	virtual void Draw(const Sprite &s, const Vec2 &pos);
};

#endif
