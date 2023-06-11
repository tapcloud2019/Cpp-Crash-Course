#include <iostream>
#include <cstdio>

void Listing6_3();
void carbon_thaw(const int&);
void Listing6_4();
short increment_as_short(void*);

int main()
{
	Listing6_4();
}

void Listing6_4()
{
	short beast{ 655 };
	auto mark_of_the_beast = increment_as_short(&beast);
	printf("%d is the mark_of_the_beast\n", mark_of_the_beast);
}

short increment_as_short(void* target)
{
	auto as_short = static_cast<short*>(target); //cast from void* to a short*
	*as_short = *as_short + 1;
	return *as_short;
}

void Listing6_3()
{
	carbon_thaw(5);
}

void carbon_thaw(const int& encased_solo)
{
	//encased_solo++; modifying const produces compile error
	auto& hibernation_sick_solo = const_cast<int&>(encased_solo); //cast away the const
	hibernation_sick_solo++;
	std::cout << "hibernation_sick_solo: " << hibernation_sick_solo << std::endl;
}