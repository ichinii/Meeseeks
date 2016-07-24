#ifndef ENGINE_SPRITE_H
#define ENGINE_SPRITE_H

#include <util/vec.h>
#include "texture.h"

class Sprite {
public:
	Vec2 m_Size;

	Sprite() = default;
	Sprite(const Sprite& other) = default;
	Sprite(Vec2 size) : m_Size(size) {}
};

#endif
