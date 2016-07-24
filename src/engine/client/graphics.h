#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H

#include <util/vec.h>

#include "graphics/sprite.h"
#include "graphics/texture.h"

class Graphics {
public:
	virtual ~Graphics() = default;

	virtual bool Init(int argc, char *argv[]) = 0;
	virtual bool Shutdown() = 0;
	virtual void Display() = 0;
	virtual void Flush() = 0;
	virtual void Draw(const Sprite &s, const Vec2 &pos) = 0;
};

#endif
