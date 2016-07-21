#include "graphics_default.h"

#include "sprite.h"

bool Graphics_Default::Init(int argc, char *argv[])
{
	m_pWindow = new sf::Window(sf::VideoMode(800, 600), "Mana");
	glewInit();

	m_pBuffer = reinterpret_cast<void*>(new unsigned char[BUFFER_SIZE]);
	m_SpriteR.SetBuffer(m_pBuffer, BUFFER_SIZE);

	return true;
}

bool Graphics_Default::Shutdown()
{
	if(m_pWindow)
		delete m_pWindow;

	return true;
}

void Graphics_Default::Flush()
{
	// upload
	// render
}

void Graphics_Default::Draw(const Sprite &s)
{
}
