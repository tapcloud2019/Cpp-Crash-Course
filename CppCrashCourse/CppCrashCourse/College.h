#pragma once

struct College
{
	char name[256];
};

void print_name(College* college_ptr)
{
	printf("%s College\n", college_ptr->name);
}

void print_names(College* colleges, size_t n_colleages)
{
	for (size_t i = 0; i < n_colleages; i++)
	{
		printf("%s polytechnic\n", colleges[i].name);
	}
}