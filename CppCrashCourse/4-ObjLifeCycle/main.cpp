#include <cstdio>
#include "RatThing.h"

void power_up_rat_thing(int);
void Listing4_2();
void power_up_rat_thing2(int);
void Listing4_3();
void Listing4_4();

static int rat_things_power = 200;
int RatThing::rat_things_power3 = 200;

int main()
{
	Listing4_4();
}

void Listing4_4()
{
	RatThing::power_up_rat_thing3(100);
	RatThing::power_up_rat_thing3(500);
}

void Listing4_3()
{
	power_up_rat_thing2(100);
	power_up_rat_thing2(500);
}

void power_up_rat_thing2(int nuclear_isotopes)
{
	static int rat_things_power2 = 200;
	rat_things_power2 += nuclear_isotopes;

	const auto waste_heat = rat_things_power2 * 20;

	if (waste_heat > 10000)
		printf("Warning! Hot doggie!\n");

	printf("Rat-thing power2: %d\n", rat_things_power2);
}

void Listing4_2()
{
	printf("Rat-thing power: %d\n", rat_things_power);

	power_up_rat_thing(100);
	printf("Rat-thing power: %d\n", rat_things_power);

	power_up_rat_thing(500);
	printf("Rat-thing power: %d\n", rat_things_power);
}

void power_up_rat_thing(int nuclear_isotopes)
{
	rat_things_power = rat_things_power + nuclear_isotopes;
	const auto waste_heat = rat_things_power * 20;

	if (waste_heat > 10000)
	{
		printf("Warning! Hot doggie\n");
	}
}