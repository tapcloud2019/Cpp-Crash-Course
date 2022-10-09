#pragma once

struct Element
{
	Element* next{}; //initialises to nullptr
	Element* previous{};
	
	void insert_after(Element* new_element)
	{
		new_element->next = this->next;
		
		if(this->next)
			this->next->previous = new_element;
		
		this->next = new_element;
		
		new_element->previous = this;
	}

	void insert_before(Element* new_element)
	{
		new_element->next = this;
		
		new_element->previous = this->previous;

		if(this->previous)
			this->previous->next = new_element;
		
		this->previous = new_element;
	}

	char prefix[2];
	short operating_number;
};
