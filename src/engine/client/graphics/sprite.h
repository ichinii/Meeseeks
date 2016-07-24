#ifndef ENGINE_SPRITE_H
#define ENGINE_SPRITE_H

#include <util/vec.h>
#include "texture.h"

class Sprite {
public:
	Vec2 m_Pos[4];
	Vec2 m_UV[4];

	Sprite() = default;
	Sprite(const Sprite& other) = default;
};

#endif
