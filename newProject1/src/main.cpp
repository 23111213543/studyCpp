#include<iostream>

#define LOG(x) std::cout << x << std::endl

class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:
	int m_LogLevel = LogLevelInfo;


public:

	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Warn(const char* message)
	{	
		if (m_LogLevel >= 0)
			LOG("[ERROR]: " << message);
		if (m_LogLevel >= 1)
			LOG("[WARNING]: " << message);
		if (m_LogLevel >= 2)
			LOG("[INFO]: " << message);
	}

};



int main()
{
	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Warn("Hello!");
	std::cin.get();


}