#pragma once
#include "Person.h"

class Keeper {
private:
	int size = 0;
	El* head = NULL;
public:
	Keeper();
	Keeper(int size);
	~Keeper();

	Person* operator[] (int id);

	int get_size();
	void insert(Person* new_data);
	void remove(int id);
	void save();
	void load();
};
