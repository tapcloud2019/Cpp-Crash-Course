#include <cstdio>
#include "ClockOfTheLongNow.h"
#include "College.h"
#include "Element.h"
#include "Avout.h"

void Listing3_1();
void Listing3_2();
void Listing3_3();
void Listing3_4();
void Listing3_5();
void Listing3_7();
void Listing3_8();
void Listing3_10();
void Listing3_11();
void Listing3_18();
void Question3_3();

int main()
{
	Question3_3();
	
	return 0;
}

void Question3_3()
{
	Element trooper1, trooper2, trooper3;
	trooper1.prefix[0] = 'W';
	trooper1.prefix[1] = 'C';
	trooper1.operating_number = 421;
	trooper1.insert_after(&trooper2);

	trooper2.prefix[0] = 'A';
	trooper2.prefix[1] = 'H';
	trooper2.operating_number = 2187;
	trooper2.insert_after(&trooper3);

	trooper3.prefix[0] = 'B';
	trooper3.prefix[1] = 'M';
	trooper3.operating_number = 005;

	Element trooper4;
	trooper2.insert_after(&trooper4);
	trooper4.prefix[0] = 'J';
	trooper4.prefix[1] = 'S';
	trooper4.operating_number = 123;

	Element trooper0;
	trooper1.insert_before(&trooper0);
	trooper0.prefix[0] = 'E';
	trooper0.prefix[1] = 'H';
	trooper0.operating_number = 5121;

	Element trooper5;
	trooper3.insert_before(&trooper5);
	trooper5.prefix[0] = 'F';
	trooper5.prefix[1] = 'R';
	trooper5.operating_number = 315;

	printf("Iterating forward:\n");
	for (Element* cursor = &trooper0; cursor; cursor = cursor->next)
	{
		printf("stormtrooper %c%c - %d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
	}

	printf("\n\nIterating backward:\n");
	for (Element* cursor = &trooper3; cursor; cursor = cursor->previous)
	{
		printf("stormtrooper %c%c - %d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
	}
}

void Listing3_18()
{
	Avout raz{ "Eramas", 3010 };
	Avout jad{ "Jad", 4000 };
	raz.announce();
	jad.announce();
}

void Listing3_11()
{
	int original = 100;
	int& original_ref = original;
	printf("Original: %d\n", original);
	printf("Original ref: %d\n", original_ref);

	int new_value = 200;
	original_ref = new_value; //reference is not reseated; 200 is assigned to the obj the ref points to
	printf("Original: %d\n", original);
	printf("New value: %d\n", new_value);
	printf("Reference: %d\n", original_ref);
}

void Listing3_10()
{
	Element trooper1, trooper2, trooper3;
	trooper1.prefix[0] = 'T';
	trooper1.prefix[1] = 'K';
	trooper1.operating_number = 421;
	trooper1.insert_after(&trooper2);

	trooper2.prefix[0] = 'F';
	trooper2.prefix[1] = 'N';
	trooper2.operating_number = 2187;
	trooper2.insert_after(&trooper3);

	trooper3.prefix[0] = 'L';
	trooper3.prefix[1] = 'S';
	trooper3.operating_number = 005;

	for (Element* cursor = &trooper1; cursor; cursor = cursor->next)
	{
		printf("stormtrooper %c%c - %d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
	}
}

void Listing3_8()
{
	ClockOfTheLongNow clock;
	clock.set_year(2022);
	printf("The year is %d.\n", clock.get_year());
	add_year(clock);
	printf("The year is %d.\n", clock.get_year());
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