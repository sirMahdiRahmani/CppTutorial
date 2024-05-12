#include <iostream>

using namespace std;

class Log
{
public:
	int LogLevelInfo = 2;
	int LogLevelWarning = 1;
	int LogLevelError = 0;

private:
	int m_LogLevel = LogLevelInfo;

public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
		{
			cout << "[Info]: " << message << endl;
		}
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
		{
			cout << "[Warning]: " << message << endl;
		}
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
		{
			cout << "[Error]: " << message << endl;
		}
	}
};

int main()
{
	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Info("Hello Info!");
	log.Warn("Hello Warning!");
	log.Error("Hello Error!");
}