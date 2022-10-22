#include <cstdio>

void power_up_rat_thing(int);
void Listing4_2();

static int rat_things_power = 200;

int main()
{
	Listing4_2();
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