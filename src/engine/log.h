#ifndef LOG_H
#define LOG_H

#include <iostream>

// TODO: rework
// TODO: color warnings and errors with ansi escaping

class Logger {
	template <typename T>
	friend Logger&& operator<< (Logger &&logger, const T &item);
private:
	std::ostream& m_OStream;
	bool m_Endl;

public:
	Logger(std::ostream &os)                                     : m_OStream(os), m_Endl(false) {}
	Logger(std::ostream &os, bool endl, const char *prefix = "") : m_OStream(os), m_Endl(endl) { m_OStream << prefix; }
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
	std::ostream &m_pNullOutBuffer;
	std::ostream &m_pConsoleOutBuffer;

public:
	BasicLogProvider()
		: m_pNullOutBuffer(std::cout)
		, m_pConsoleOutBuffer(std::cout)
	{}

	std::ostream &GetNullOutBuffer() { return m_pNullOutBuffer; }
	std::ostream &GetConsoleOutBuffer() { return m_pNullOutBuffer; }
	Logger Info() { return Logger(m_pConsoleOutBuffer, false,        "   [INFO] "); }
	Logger Debug() { return Logger(m_pConsoleOutBuffer, false,       "  [DEBUG] "); }
	Logger Warning() { return Logger(m_pConsoleOutBuffer, false,     "[WARNING] "); }
	Logger Error() { return Logger(m_pConsoleOutBuffer, false,       "  [ERROR] "); }
	Logger operator() () { return Logger(m_pConsoleOutBuffer, false, "          "); }
};

class LogProvider {
private:
	BasicLogProvider m_BasicLogProvider;

public:
	LogProvider() : Base(m_BasicLogProvider) {}

	BasicLogProvider &Base;
	Logger Info() { return Logger(m_BasicLogProvider.GetConsoleOutBuffer(), true,        "   [INFO] "); }
	Logger Debug() { return Logger(m_BasicLogProvider.GetConsoleOutBuffer(), true,       "  [DEBUG] "); }
	Logger Warning() { return Logger(m_BasicLogProvider.GetConsoleOutBuffer(), true,     "[WARNING] "); }
	Logger Error() { return Logger(m_BasicLogProvider.GetConsoleOutBuffer(), true,       "  [ERROR] "); }
	Logger operator() () { return Logger(m_BasicLogProvider.GetConsoleOutBuffer(), true, "          "); }
};

static LogProvider Log;

#endif
