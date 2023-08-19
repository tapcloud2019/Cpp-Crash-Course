#pragma once
#include <stdexcept>
#include <type_traits>


struct Highlander
{
	Highlander() = default;
	Highlander(const Highlander&) = delete; //this copy constructor is not meant to be used
};

//embed requires expressions directly into the template definition
template<typename T> requires std::is_copy_constructible<T>::value
T get_copy(T* pointer)
{
	if (!pointer)
		throw std::runtime_error{"Null pointer dereference"};

	return *pointer;
}