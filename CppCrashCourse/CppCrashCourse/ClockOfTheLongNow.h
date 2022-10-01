#pragma once

struct ClockOfTheLongNow
{
	void add_year()
	{
		year++;
	}

	bool set_year(int year)
	{
		if (year < 2019) return false;
		this->year = year;

		return true;
	}

	int get_year() const
	{
		return year;
	}

private:
	int year;
};

void add_year(ClockOfTheLongNow& clock)
{
	clock.set_year(clock.get_year() + 1);
}

bool is_leap_year(const ClockOfTheLongNow& clock)
{
	if (clock.get_year() % 4 > 0) return false;
	if (clock.get_year() % 100 > 0) return true;
	if (clock.get_year() % 400 > 0) return false;

	return true;
}