#ifndef ENGINE_GRAPHICS_DEFAULT_H
#define ENGINE_GRAPHICS_DEFAULT_H

#include <GL/glew.h>
#include <SFML/Window.hpp>

#include "../graphics.h"
#include <util/vec.h>
#include "sprite.h"
#include "renderer/spriterenderer.h"

class Graphics_Default : public Graphics {
private:
	sf::Window *m_pWindow;

	static const size_t BUFFER_SIZE = 1024;
	void *m_pBuffer;

	SpriteRenderer m_SpriteR;

public:
	~Graphics_Default() = default;

	bool Init(int argc, char *argv[]);
	bool Shutdown();
	void Flush();
	void Draw(const Sprite &s);
	//void Draw(Vec2 pos, Vec2 size) { m_SpriteR.Draw(pos, size); }
};

#endif
