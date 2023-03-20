#pragma once
#include <Windows.h>
#include <cstdio>

struct TimerClass
{
	TimerClass(const char* name) : moved(false)
	{
		GetSystemTime(&timestamp);

		this->name = new char[strlen(name)];
		strcpy(this->name, name);

		printf("%s timer created", this->name);
	}

	~TimerClass()
	{
		if (!moved)
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

		delete[] name;
	}

	//copy constructor
	TimerClass(const TimerClass& other) : timestamp{ other.timestamp }, 
											moved{ other.moved }
	{
		delete[] name;
		name = new char[strlen(other.name)];
		strcpy(name, other.name);
	}

	//copy assignment operator
	TimerClass& operator=(const TimerClass& other)
	{
		if (this == &other) return *this;

		timestamp = other.timestamp;
		moved = other.moved;
		
		delete[] name;
		name = new char[strlen(other.name)];
		strcpy(name, other.name);

		return *this;
	}

	//move constructor
	TimerClass(TimerClass&& other) noexcept : timestamp{ other.timestamp }, 
												moved{other.moved},
												name{other.name}
	{
		other.timestamp.wYear = 1900;
		other.timestamp.wMonth = 1;
		other.timestamp.wDay = 1;
		other.timestamp.wHour = 1;
		other.timestamp.wMinute = 1;
		other.timestamp.wSecond = 1;
		other.timestamp.wMilliseconds = 1;
		other.moved = true;
		other.name = nullptr;
	}

	//move assignment operator
	TimerClass& operator=(TimerClass&& other) noexcept
	{
		if (this == &other) return *this;

		timestamp = other.timestamp;
		name = other.name;
		moved = other.moved;

		other.timestamp.wYear = 1900;
		other.timestamp.wMonth = 1;
		other.timestamp.wDay = 1;
		other.timestamp.wHour = 1;
		other.timestamp.wMinute = 1;
		other.timestamp.wSecond = 1;
		other.timestamp.wMilliseconds = 1;
		other.moved = true;
		other.name = nullptr;

		return *this;
	}

private:
	SYSTEMTIME timestamp;
	bool moved;
	char* name;
};