#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "ListItem.h"
using namespace std;

class linkedList
{
public:
	linkedList();
	~linkedList();

	void print();
	void insert(Bunny);
	void incrementAge();

	void resetBirthCheck();
	void checkAge();
	void reproduction();
	void starvation();
	void setBunnyCount(int);
	int getBunnyCount();

private:
	void remove(listItem* &, listItem* &);
	char checkMale();
	int checkFemale();
	Bunny mother();
	listItem* head;
	int bunnyCount;
	int femaleCount;

};

#endif