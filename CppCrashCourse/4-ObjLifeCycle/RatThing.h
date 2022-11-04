#pragma once
#include <cstdio>

struct RatThing
{
	static int rat_things_power3;

	static void power_up_rat_thing3(int nuclear_isotopes)
	{
		rat_things_power3 += nuclear_isotopes;
		const auto waste_heat = rat_things_power3 * 20;

		if (waste_heat > 10000)
		{
			printf("Warning! Hot doggie!\n");
		}

		printf("Rat-thing power: %d\n", rat_things_power3);
	}
};