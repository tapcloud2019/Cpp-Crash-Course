#include <cstdio>

void Listing7_1();
int confusing(int&);

int main()
{
	Listing7_1();
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