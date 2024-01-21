#include <cstdio>
#include <limits>
#include <cstdint>
#include "CheckedInteger.h"
#include "Heap.h"
#include "Point.h"

void Listing7_1();
int confusing(int&);
void Listing7_3();
Heap heap;
//void* operator new(size_t n_bytes);
//void operator delete(void* p);
void Listing7_6();
void Listing7_7();
void Listing7_8();
void Listing7_9();
void print_addr(void*);
void Listing7_10();
void Listing7_11();
void Listing7_12();

int main()
{
	Listing7_12();
}

void Listing7_12()
{
	int64_t b = std::numeric_limits<int64_t>::max();
	int32_t c(b); //compiler abides without braced intialiser

	if (c != b) printf("Narrowing conversion. Fail!\n");
}

void Listing7_11()
{
	int32_t a = 100;
	int64_t b{ a }; //braced initalisation ensures safe, non narrowing conversions

	if (a == b) printf("Non narrowing conversion. Pass!\n");

	//int32_t c{ b }; //compile error; fails braced initialisation non narrowing requirement
}

void Listing7_10()
{
	int x{};
	print_addr(&x);
	print_addr(nullptr);
}

void print_addr(void* x)  //pointers implicitly convert to void*
{
	printf("0x%p\n", x);
}

void Listing7_9()
{
	double x = std::numeric_limits<float>::max(); //safe (float to double)
	long double y = std::numeric_limits<double>::max(); //safe (double to long double)
	float z = std::numeric_limits<long double>::max(); //undefined behaviour (long double to float)
	printf("x: %g\ny:%Lg\nz:%g", x, y, z);
}

void Listing7_8()
{
	//0b111111111 = 511
	uint8_t x = 0b111111111; //255 for unsigned 8 bit integer
	int8_t y = 0b111111111; //implementation dependent for signed; -1 on Win 10 x64; Use braced initialisation {} to avoid narrowing conversions
	printf("x: %u\ny: %d\n", x, y);
}

void Listing7_7()
{
	const auto point_size = sizeof(Point);
	std::byte data[3 * point_size];
	printf("Data starts at %p\n", data);

	auto point1 = new(&data[0 * point_size])Point{}; //placement operator. Construct object in preallocated memory
	auto point2 = new(&data[1 * point_size])Point{};
	auto point3 = new(&data[2 * point_size])Point{};

	point1->~Point(); //cannot use delete to release. Call the object's destructor directly exactly once
	point2->~Point();
	point3->~Point();
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