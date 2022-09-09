#pragma once

struct College
{
	char name[256];
};

void print_name(College* college_ptr)
{
	printf("%s College\n", college_ptr->name);
}