#ifndef BUNNY_H
#define BUNNY_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Bunny
{
public:
	Bunny();
	Bunny(int, string);

	int getID();

	void setName(string);
	string getName();

	void setAge(int);
	int getAge();

	void setGender(char);
	char getGender();

	void setColour(string);
	string getColour();

	void setBirthCheck(bool);
	bool getBirthCheck();

	Bunny createBunny();

	void printDetails();

private:
	char randGender(int, int);
	int bunnyID;
	string name;
	int age;
	char gender;
	string colour;
	bool birthCheck;
};

#endif // !BUNNY_H