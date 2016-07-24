#include <engine/log.h>

#include <engine/client/graphics.h>
#include <engine/client/graphics/graphics_default.h>

int main(int argc, char *argv[])
{
	{
		Log() << "Look at me!";

		Graphics *pGraphics = new Graphics_Default();
		pGraphics->Init(argc, argv);

		Sprite s(Vec2(1, 1));
		pGraphics->Draw(s, Vec2(0, 0));

		pGraphics->Display();

		sf::sleep(sf::seconds(1));

		pGraphics->Shutdown();
	}

	return 0;
}
