#include <engine/log.h>

#include <engine/client/graphics.h>
#include <engine/client/graphics/graphics_default.h>

void printGLErrors() {
  static int i = 0;
  GLenum err = GL_NO_ERROR;
  while((err = glGetError()) != GL_NO_ERROR)
  {
    Log.Error() << "[GL] "<< i++ << ": 0x" << std::hex << err;
  }
}

int main(int argc, char *argv[])
{
	{
		Log() << "Look at me!";

		Graphics *pGraphics = new Graphics_Default();
		pGraphics->Init(argc, argv);
		pGraphics->Clear();

		Sprite s;
		s.m_Pos[0] = Vec2(0, 0);
		s.m_Pos[1] = Vec2(1, 0);
		s.m_Pos[2] = Vec2(1, 1);
		s.m_Pos[3] = Vec2(0, 1);
		pGraphics->Draw(s, Vec2(0, 0));

		pGraphics->Display();

		sf::sleep(sf::seconds(1));

		pGraphics->Shutdown();
	}

	printGLErrors();

	return 0;
}
