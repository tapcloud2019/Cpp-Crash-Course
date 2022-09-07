#pragma once

struct ClockOfTheLongNow
{
	void add_year()
	{
		year++;
	}

	bool set_year(int new_year)
	{
		if (new_year < 2019) return false;
		year = new_year;

		return true;
	}

	int get_year()
	{
		return year;
	}

private:
	int year;
};