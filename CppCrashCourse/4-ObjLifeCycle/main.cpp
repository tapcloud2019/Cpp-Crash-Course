#include <cstdio>
#include <stdexcept>
#include "RatThing.h"
#include "Tracer.h"
#include "groucho.h"
#include "CyberdyneSeries800.h"

void power_up_rat_thing(int);
void Listing4_2();
void power_up_rat_thing2(int);
void Listing4_3();
void Listing4_4();
void Listing4_6();
void Listing4_9();
void Listing4_13();

static int rat_things_power = 200;
int RatThing::rat_things_power3 = 200;
static Tracer t1{ "Static variable" };
thread_local Tracer t2{ "Thread-local variable" };

int main()
{
	Listing4_13();
}

void Listing4_13()
{
	try
	{
		CyberdyneSeries800 t800;
		
		throw std::runtime_error{ "Come with me if you want to live.\n" };
	}
	catch (const std::exception& e)
	{
		printf("Caught exception:%s\n", e.what());
	}
}

void Listing4_9()
{
	Groucho groucho;
	
	try
	{
		groucho.forget(0xC0DE);
		groucho.forget(0xFACE);
		groucho.forget(0xC0FFEE);
	}
	catch (const std::runtime_error& e)
	{
		printf("Exception caught with message: %s\n", e.what());
	}
}

void Listing4_6()
{
	const auto t2_ptr = &t2;
	printf("A\n");
	Tracer t3{ "Automatic variable" };
	printf("B\n");
	const auto* t4 = new Tracer{ "Dynamic variable" };
	printf("C\n");
	delete t4;
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