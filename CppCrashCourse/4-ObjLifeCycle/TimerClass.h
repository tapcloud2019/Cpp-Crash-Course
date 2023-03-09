#pragma once
#include <Windows.h>
#include <cstdio>

struct TimerClass
{
	TimerClass()
	{
		GetSystemTime(&timestamp);
	}

	~TimerClass()
	{
		SYSTEMTIME currentTime;
		FILETIME currentTimeFT;
		GetSystemTime(&currentTime);
		SystemTimeToFileTime(&currentTime, &currentTimeFT);

		FILETIME timestampFT;
		SystemTimeToFileTime(&timestamp, &timestampFT);

		LONGLONG diffInTicks =
			reinterpret_cast<LARGE_INTEGER*>(&currentTimeFT)->QuadPart -
			reinterpret_cast<LARGE_INTEGER*>(&timestampFT)->QuadPart;

		LONGLONG diffInMillis = diffInTicks / 10000;

		printf("The timespan is %lld ms", diffInMillis);
	}

	//copy constructor
	TimerClass(const TimerClass& other): timestamp{other.timestamp}{}

	//copy assignment operator
	TimerClass& operator=(const TimerClass& other)
	{
		if (this == &other) return *this;

		timestamp = other.timestamp;

		return *this;
	}

private:
	SYSTEMTIME timestamp;
};