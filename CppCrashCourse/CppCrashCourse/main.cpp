#include <cstdio>
#include "ClockOfTheLongNow.h"
#include "College.h"

void Listing3_1();
void Listing3_2();
void Listing3_3();
void Listing3_4();
void Listing3_5();
void Listing3_7();

int main()
{
	Listing3_7();
	
	return 0;
}

void Listing3_7()
{
	char lower[] = "abc?e";
	char upper[] = "ABC?E";
	char* upper_ptr = upper; //same as &upper[0]

	*(lower + 3) = 'd';
	*(upper_ptr + 3) = 'D';

	char letter_d = *(lower + 3);
	char letter_D = *(upper_ptr + 3);

	printf("lower: %s\nupper: %s\n", lower, upper);
}

void Listing3_5()
{
	College polytechnics[] = { "Ngee Ann", "Nanyang", "Temasek", "Singapore"};

	print_names(polytechnics, sizeof(polytechnics) / sizeof(College));
}

void Listing3_4()
{
	College best_colleges[] = { "NTU","NUS","SMU" };

	print_name(best_colleges);
}

void Listing3_3()
{
	ClockOfTheLongNow clock;
	ClockOfTheLongNow* clock_ptr = &clock;

	clock_ptr->set_year(2020);
	printf("Address of clock: %p\n", clock_ptr);
	printf("Value of clock's year: %d\n", clock_ptr->get_year());
}

void Listing3_2()
{
	int gettysburg{};
	int* gettysburg_address = &gettysburg;
	printf("Value at gettysburg_address: %d\n", *gettysburg_address);
	printf("Gettysburg address: %p\n", gettysburg_address);

	*gettysburg_address = 17325;
	printf("Value at gettysburg_address: %d\n", *gettysburg_address);
	printf("Gettysburg address: %p\n", gettysburg_address);
}

void Listing3_1()
{
	int gettysburg{};
	printf("gettysburg: %d\n", gettysburg);

	int* gettysburg_address = &gettysburg;
	printf("&gettysburg: %p\n", gettysburg_address);
}