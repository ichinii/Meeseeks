#include "graphics_default.h"
#include "sprite.h"

Graphics_Default::Graphics_Default()
{
	m_pWindow = nullptr;
	m_pPolygonPipeline = nullptr;
	m_pPolygonPoser = nullptr;
	m_pBuffer = nullptr;
}

Graphics_Default::~Graphics_Default()
{
	Shutdown();
}

bool Graphics_Default::Init(int argc, char *argv[])
{
	Shutdown();

	m_pWindow = new sf::Window(sf::VideoMode(800, 600), "Look at me!");
	glewInit();

	Shader vertexShader(VERTEX_SHADER);
	Shader fragmentShader(FRAGMENT_SHADER);
	vertexShader.LoadFromFile("data/shader/vertex.glsl");
	fragmentShader.LoadFromFile("data/shader/fragment.glsl");

	m_pPolygonPipeline = new Pipeline();
	m_pPolygonPipeline->AttachShader(vertexShader);
	m_pPolygonPipeline->AttachShader(fragmentShader);
	m_pPolygonPipeline->Link();
	m_pPolygonPipeline->DetachShader(vertexShader);
	m_pPolygonPipeline->DetachShader(fragmentShader);

	m_pBuffer = reinterpret_cast<void*>(new unsigned char[BUFFER_SIZE]);

	m_pPolygonPoser = new PolygonPoser(m_pPolygonPipeline);
	m_pPolygonPoser->SetBuffer(m_pBuffer, BUFFER_SIZE);

	return true;
}

bool Graphics_Default::Shutdown()
{
	delete m_pWindow;
	delete m_pPolygonPipeline;
	delete m_pPolygonPoser;
	delete[] reinterpret_cast<unsigned char*>(m_pBuffer);
	m_pWindow = nullptr;
	m_pPolygonPipeline = nullptr;
	m_pPolygonPoser = nullptr;
	m_pBuffer = nullptr;

	return true;
}

void Graphics_Default::Display()
{
	m_pWindow->display();
}

void Graphics_Default::Flush()
{
	// upload
	// render
}


void Graphics_Default::Draw(const Sprite &s, const Vec2 &pos)
{
	m_pPolygonPoser->Draw(s, pos);
}
