#include <cstdio>
#include <limits>
#include "CheckedInteger.h"

void Listing7_1();
int confusing(int&);
void Listing7_3();

int main()
{
	Listing7_3();
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