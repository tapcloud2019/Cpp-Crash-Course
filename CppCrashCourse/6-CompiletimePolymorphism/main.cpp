#include <iostream>
#include <cstdio>
#include <stdexcept>

void Listing6_3();
void carbon_thaw(const int&);
void Listing6_4();
short increment_as_short(void*);
void Listing6_7();
template<typename To, typename From>
To narrow_cast(From value);

int main()
{
	Listing6_7();
}

void Listing6_7()
{
	int perfect{ 496 };
	const auto perfect_short = narrow_cast<short>(perfect);
	printf("perfect_short: %d\n", perfect_short);

	try
	{
		int cyclic{ 142857 };
		const auto cyclic_short = narrow_cast<short>(cyclic);
		printf("cyclic_short: %d\n", cyclic_short);
	}
	catch (const std::runtime_error& e)
	{
		printf("Exception: %s\n", e.what());
	}
}

template<typename To, typename From>
To narrow_cast(From value)
{
	const auto converted = static_cast<To>(value);
	const auto backwards = static_cast<From>(converted);

	if (value != backwards)
		throw std::runtime_error("Narrowed!");

	return converted;
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
