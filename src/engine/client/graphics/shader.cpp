#include "shader.h"
#include <engine/log.h>
#include <fstream>
#include <sstream>
#include <vector>

GLuint LoadShaderFromFile(GLuint type, const char *filepath)
{
	Log.Debug() << "Loading shadercode from file '" << filepath << '\'';

	std::ifstream filestream;
	filestream.open(filepath, std::ifstream::in);

	std::string shadercode;
	if(filestream.is_open())
	{
		std::string line;
		while(std::getline(filestream, line))
		{
			shadercode.append(line + '\n');
		}
		filestream.close();
	}
	else
	{
		Log.Error() << "Failed to open file";
	}

	return LoadShaderFromString(type, shadercode.c_str());
}

GLuint LoadShaderFromString(GLuint type, const char *shadercode)
{
	Log.Debug() << "Compiling shader with type '" << type << '\'';

	GLuint shaderID = glCreateShader(type);
	glShaderSource(shaderID, 1, &shadercode, nullptr);
	glCompileShader(shaderID);

	GLint result = GL_FALSE;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

	if(!result)
	{
		Log.Error() << "Error compiling shader with error message:";

		GLint length;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> msg(length + 1);
		msg[length] = '\0';
		glGetShaderInfoLog(shaderID, length, nullptr, &msg[0]);

		Log() << &msg[0];
	}

	return shaderID;
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
	m_ShaderID = LoadShaderFromFile((GLuint)m_Type, filepath);
}

void Shader::LoadFromString(const char *shadercode)
{
	if(m_ShaderID)
		glDeleteShader(m_ShaderID);
	m_ShaderID = LoadShaderFromString((GLuint)m_Type, shadercode);
}
