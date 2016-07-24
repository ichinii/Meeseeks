#ifndef ENGINE_POSER_H
#define ENGINE_POSER_H

#include "pipeline.h"

class Poser {
protected:
	Pipeline *m_pPipeline;
	void *m_pBuffer;
	size_t m_CapacityBytes;

public:
	Poser() = delete;
	Poser(Pipeline *pPipeline) : m_pPipeline(pPipeline) {}
	virtual ~Poser() = default;

	virtual void SetBuffer(void *pBuffer, size_t size) = 0;
	virtual void Flush() = 0;
};

#endif
