#pragma once
#include <map>
#include <cstdio>

int findMode(const int* values, size_t length)
{
	std::map<int, int> valueCounts; //key is the element of the values array; value is the count of the element
	int mode{};
	int biggestCount{};

	//add array elements as keys to the map
	for (size_t i = 0; i < length; i++)
	{
		valueCounts.insert({ *(values + i),0 });
	}

	//assign count of array elements as values to the keys
	for (auto itr = valueCounts.begin(); itr != valueCounts.end(); ++itr)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (itr->first == *(values + i))
				(itr->second)++;
		}

		printf("%d: %d\n", itr->first, itr->second);
	}

	biggestCount = valueCounts.begin()->second;
	for (auto itr = valueCounts.begin(); itr != valueCounts.end(); ++itr)
	{
		if (biggestCount < itr->second)
		{
			mode = itr->first;
			biggestCount = itr->second;
		}
	}

	return mode;
}

template<typename T>
T findModeT(const T* values, size_t length)
{
	std::map<T, int> valueCounts; //key is the element of the values array; value is the count of the element
	T mode{};
	int biggestCount{};

	//add array elements as keys to the map
	for (size_t i = 0; i < length; i++)
	{
		valueCounts.insert({ *(values + i),0 });
	}

	//assign count of array elements as values to the keys
	for (auto itr = valueCounts.begin(); itr != valueCounts.end(); ++itr)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (itr->first == *(values + i))
				(itr->second)++;
		}

		printf("%d: %d\n", itr->first, itr->second);
	}

	biggestCount = valueCounts.begin()->second;
	for (auto itr = valueCounts.begin(); itr != valueCounts.end(); ++itr)
	{
		if (biggestCount < itr->second)
		{
			mode = itr->first;
			biggestCount = itr->second;
		}
	}

	return mode;
}

template<typename T, size_t SIZE>
T findModeWithArrayT(T (&values)[SIZE])
{
	std::map<T, int> valueCounts; //key is the element of the values array; value is the count of the element
	T mode{};
	int biggestCount{};

	//add array elements as keys to the map
	for (size_t i = 0; i < SIZE; i++)
	{
		valueCounts.insert({ values[i],0});
	}

	//assign count of array elements as values to the keys
	for (auto itr = valueCounts.begin(); itr != valueCounts.end(); ++itr)
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			if (itr->first == values[i])
				(itr->second)++;
		}

		printf("%d: %d\n", itr->first, itr->second);
	}

	biggestCount = valueCounts.begin()->second;
	for (auto itr = valueCounts.begin(); itr != valueCounts.end(); ++itr)
	{
		if (biggestCount < itr->second)
		{
			mode = itr->first;
			biggestCount = itr->second;
		}
	}

	return mode;
}

template<typename T>
concept integral = std::is_integral_v<T>;

template<integral T>
T findModeConcept(const T* values, size_t length)
{
	std::map<T, int> valueCounts; //key is the element of the values array; value is the count of the element
	T mode{};
	int biggestCount{};

	//add array elements as keys to the map
	for (size_t i = 0; i < length; i++)
	{
		valueCounts.insert({ *(values + i),0 });
	}

	//assign count of array elements as values to the keys
	for (auto itr = valueCounts.begin(); itr != valueCounts.end(); ++itr)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (itr->first == *(values + i))
				(itr->second)++;
		}

		printf("%d: %d\n", itr->first, itr->second);
	}

	biggestCount = valueCounts.begin()->second;
	for (auto itr = valueCounts.begin(); itr != valueCounts.end(); ++itr)
	{
		if (biggestCount < itr->second)
		{
			mode = itr->first;
			biggestCount = itr->second;
		}
	}

	return mode;
}