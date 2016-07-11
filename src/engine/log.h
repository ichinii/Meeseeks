#ifndef ENGINE_LOG_H
#define ENGINE_LOG_H

#include <iostream>

class Logger {
	template <typename T>
	friend Logger&& operator<< (Logger &&logger, const T &item);
private:
	std::ostream& m_OStream;
	bool m_Endl;

public:
	Logger(std::ostream &os)            : m_OStream(os), m_Endl(false) {}
	Logger(std::ostream &os, bool endl) : m_OStream(os), m_Endl(endl) {}
	Logger(const Logger &) = default;
	~Logger() { if(m_Endl) m_OStream << std::endl; }
};

template <typename T>
Logger&& operator<< (Logger &&logger, const T& item)
{
	logger.m_OStream << item;
	return std::move(logger);
}

class BasicLogProvider {
private:
	std::ostream& m_pNullOutBuffer;
	std::ostream& m_pConsoleOutBuffer;

public:
	BasicLogProvider()
		: m_pNullOutBuffer(std::cout)
		, m_pConsoleOutBuffer(std::cout)
	{}

	std::ostream &GetNullOutBuffer() { return m_pNullOutBuffer; }
	std::ostream &GetConsoleOutBuffer() { return m_pNullOutBuffer; }
	Logger Info() { return Logger(m_pConsoleOutBuffer); }
	Logger Debug() { return Logger(m_pConsoleOutBuffer); }
	Logger Error() { return Logger(m_pConsoleOutBuffer); }
	Logger operator() () { return Info(); }
};

class LogProvider {
private:
	BasicLogProvider m_BasicLogProvider;

public:
	LogProvider() : Base(m_BasicLogProvider) {}

	BasicLogProvider &Base;
	Logger Info() { return Logger(m_BasicLogProvider.GetConsoleOutBuffer(), true); }
	Logger Debug() { return Logger(m_BasicLogProvider.GetConsoleOutBuffer(), true); }
	Logger Error() { return Logger(m_BasicLogProvider.GetConsoleOutBuffer(), true); }
	Logger operator() () { return Info(); }
};

static LogProvider Log;

#endif
