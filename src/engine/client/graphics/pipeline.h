#ifndef ENGINE_PIPELINE_H
#define ENGINE_PIPELINE_H

#include <GL/glew.h>
#include <engine/log.h>
#include "shader.h"

class Pipeline {
private:
	GLuint m_ProgramID;

	static Pipeline *s_CurrentPipeline;

public:
	Pipeline() { m_ProgramID = glCreateProgram(); }
	Pipeline(const Pipeline &) = delete;
	Pipeline(Pipeline &&other) { std::swap(m_ProgramID, other.m_ProgramID); }
	~Pipeline() { glDeleteProgram(m_ProgramID); }

	Pipeline &operator= (Pipeline &) = delete;
	Pipeline &operator= (Pipeline &&other) { std::swap(m_ProgramID, other.m_ProgramID); return *this; }

	void AttachShader(Shader &shader) { glAttachShader(m_ProgramID, shader.m_ShaderID); }
	bool DetachShader(Shader &shader) { glDetachShader(m_ProgramID, shader.m_ShaderID); return true; }
	void Link() { glLinkProgram(m_ProgramID); }
	void MakeCurrent();
};

#endif
