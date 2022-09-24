#pragma once

struct Element
{
	Element* next{}; //initialises to nullptr
	
	void insert_after(Element* new_element)
	{
		new_element->next = next;
		next = new_element;
	}

	char prefix[2];
	short operating_number;
};
