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
void Listing6_11();
template<typename T>
T mean(const T* values, size_t length);

int main()
{
	Listing6_11();
}

void Listing6_11()
{
	const double nums_d[]{ 1.0, 2.0, 3.0, 4.0 };
	const auto result1 = mean<double>(nums_d, 4);
	printf("double: %f\n", result1);

	const float nums_f[]{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto result2 = mean<float>(nums_f, 4);
	printf("float: %f\n", result2);

	const size_t nums_c[]{ 1, 2, 3, 4 };
	const auto result3 = mean<size_t>(nums_c, 4);
	printf("size_t: %zu\n", result3);
}

template<typename T>
T mean(const T* values, size_t length)
{
	T result{};

	for (size_t i{}; i < length; i++)
		result += values[i];

	return result / length;
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
