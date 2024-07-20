#include "pch.h"

using namespace std;


void Log(const char* message)
{
	cout << message << endl;
}


class Log
{
public:
	enum
	{
		LevelError = 0, LevelWarning, LevelInfo
	};

private:
	int m_LogLevel = LevelInfo;

public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
		{
			cout << "[Info]: " << message << endl;
		}
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
		{
			cout << "[Warning]: " << message << endl;
		}
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
		{
			cout << "[Error]: " << message << endl;
		}
	}
};