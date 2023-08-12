#pragma once
#include <concepts>
#include <type_traits>


template<typename T>
concept Averagable = std::is_default_constructible<T>::value && requires(T a, T b)
{
	{a += b} -> std::convertible_to<T>;
	{a / size_t{1}} -> std::convertible_to<T>;
};

template<Averagable T> //using the Averagable concept
T mean(T* values, size_t length)
{
	T result{};

	for (size_t i{}; i < length; i++)
	{
		result += values[i];
	}

	return result / length;
}
