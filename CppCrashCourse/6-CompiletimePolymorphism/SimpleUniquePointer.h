#pragma once

template<typename T>
struct SimpleUniquePointer
{
	SimpleUniquePointer() = default;
	SimpleUniquePointer(T* pointer) : pointer{ pointer } {}
	~SimpleUniquePointer()
	{
		if (pointer) delete pointer;
	}

	//disable copying constructor and assignment
	SimpleUniquePointer(const SimpleUniquePointer&) = delete;
	SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;

	//move constructor and assignment
	SimpleUniquePointer(SimpleUniquePointer&& other) noexcept : pointer{ other.pointer }
	{
		other.pointer = nullptr;
	}
	SimpleUniquePointer& operator=(const SimpleUniquePointer&& other) noexcept
	{
		if (pointer) delete pointer;
		pointer = other.pointer;
		other.pointer = nullptr;

		return *this;
	}

	T* get()
	{
		return pointer;
	}

private:
	T* pointer;
};