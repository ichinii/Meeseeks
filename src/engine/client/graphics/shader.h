#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <GL/glew.h>

enum ShaderType {
	VERTEX_SHADER = GL_VERTEX_SHADER,
	FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

GLuint LoadShaderFromFile(GLuint type, const char *filepath);
GLuint LoadShaderFromString(GLuint type, const char *shadercode);

class Shader {
private:
	friend class Pipeline;

	const ShaderType m_Type;
	GLuint m_ShaderID;

public:
	Shader(const ShaderType type) : m_Type(type) { m_ShaderID = 0; }
	Shader(const Shader &) = delete;
	Shader(Shader &&other);
	~Shader() { if(m_ShaderID != 0) glDeleteShader(m_ShaderID); }

	Shader &operator= (const Shader &) = delete;

	void LoadFromFile(const char *filepath);
	void LoadFromString(const char *shadercode);

	bool operator== (Shader &o) { return m_ShaderID == o.m_ShaderID; }
	bool operator!= (Shader &o) { return m_ShaderID != o.m_ShaderID; }
};

#endif
