#include <cstdio>
#include <limits>
#include "CheckedInteger.h"
#include "Heap.h"

void Listing7_1();
int confusing(int&);
void Listing7_3();
Heap heap;
void* operator new(size_t n_bytes);
void operator delete(void* p);
void Listing7_6();

int main()
{
	Listing7_6();
}


void Listing7_6()
{
	printf("Buckets: %p\n", heap.buckets);
	auto breakfast = new unsigned int{ 0xC0FFEE };
	auto dinner = new unsigned int{ 0xDEADBEEF };
	printf("breakfast: %p 0x%x\n", breakfast, *breakfast);
	printf("Dinner: %p 0x%x\n", dinner, *dinner);
	delete breakfast;
	delete dinner;

	try 
	{
		while (true)
		{
			new char;
			printf("Allocated a char \n");
		}
	}
	catch (const std::bad_alloc)
	{
		printf("std::bad_alloc caught \n");
	}
}

void* operator new(size_t n_bytes)
{
	return heap.allocate(n_bytes);
}

void operator delete(void* p)
{
	return heap.free(p);
}

void Listing7_3()
{
	CheckedInteger a{ 100 };
	auto b = a + 200;
	printf("a + 200 = %u\n", b.value);

	try
	{
		auto c = a + std::numeric_limits<unsigned int>::max();
	}
	catch (const std::overflow_error& e)
	{
		printf("(a + max) exception: %s\n", e.what());
	}
}

void Listing7_1()
{
	int x{};
	auto y = confusing(x);
	printf("x: %d\ny: %d\n", x, y);
}

int confusing(int& x)
{
	return x = 9, x++, x / 2; //comma operator; does not promote cleaner code
}