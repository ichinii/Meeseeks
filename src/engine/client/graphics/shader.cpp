#include "shader.h"

GLuint LoadShaderFromFile(ShaderType type, const char *filepath)
{
	return 0;
}

GLuint LoadShaderFromString(ShaderType type, const char *shadercode)
{
	return 0;
}

//#define ASSERT(expr) if(!expr) Log.Error() << '\'' << #expr << "' assertion failed @ " << __FILE__ << '(' << __LINE__  << ')';

Shader::Shader(Shader &&other)
	: m_Type(other.m_Type)
{
	m_ShaderID = other.m_ShaderID;
	other.m_ShaderID = 0;
}

void Shader::LoadFromFile(const char *filepath)
{
	if(m_ShaderID)
		glDeleteShader(m_ShaderID);
	m_ShaderID = LoadShaderFromFile(m_Type, filepath);
}

void Shader::LoadFromString(const char *shadercode)
{
	if(m_ShaderID)
		glDeleteShader(m_ShaderID);
	m_ShaderID = LoadShaderFromString(m_Type, shadercode);
}
