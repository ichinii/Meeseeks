#include "pipeline.h"

Pipeline *Pipeline::s_CurrentPipeline = nullptr;

void Pipeline::MakeCurrent()
{
	if(s_CurrentPipeline != this)
	{
		s_CurrentPipeline = this;
		glUseProgram(m_ProgramID);
	}
}
