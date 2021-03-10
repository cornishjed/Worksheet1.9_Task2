#include "Bunny.h"

Bunny::Bunny()
{
}

Bunny::Bunny(int a, string c)
{
	age = a;
	colour = c;
}

int Bunny::getID()
{
	return bunnyID;
}

void Bunny::setName(string n)
{
	name = n;
}

string Bunny::getName()
{
	return name;
}

void Bunny::setAge(int a)
{
	age = a;
}

int Bunny::getAge()
{
	return age;
}

void Bunny::setGender(char g)
{
	gender = g;
}

char Bunny::getGender()
{
	return gender;
}

void Bunny::setColour(string c)
{
	colour = c;
}

string Bunny::getColour()
{
	return colour;
}

void Bunny::setBirthCheck(bool bc)
{
	birthCheck = bc;
}

bool Bunny::getBirthCheck()
{
	return birthCheck;
}

Bunny Bunny::createBunny()
{
	static int bunnyID = 0;

	string names[] = { "Fluffy", "Cuddles", "Spike", "Charles", "Weston", "Light", "Spot", "Branston", "Red", "Jupiter" };
	string colours[] = { "white", "brown", "black", "spotted" };
	int randName;
	int randName2;
	int randColour;
	int randColour2;
	char gender;
	int randAge;
	int randChoose;

	randName = rand() % 10;
	randName2 = rand() % 9;
	randAge = rand() % 11;
	gender = randGender(randName, randAge);
	randColour = rand() % 4;
	randColour2 = rand() % 4;
	randChoose = rand() % 2;

	Bunny newBunny;

	newBunny.setName(names[randName]);
	newBunny.setAge(randAge);
	newBunny.setGender(randGender(randName, randAge));
	if (randChoose == 0)
		newBunny.setColour(colours[randColour]);
	else
		newBunny.setColour(colours[randColour2]);
	newBunny.bunnyID = bunnyID++;
	newBunny.setBirthCheck(false);

	return newBunny;
}

void Bunny::printDetails()
{
	cout << "Name: " << name << "\tAge: " << age << "\tGender: " << gender << "\tColour: " << colour << endl;
}


char Bunny::randGender(int a, int b)
{
	if (a == 0)
		a++;

	if (b == 0)
		b++;

	if (a % b == 0)
		return 'M';
	else
		return 'F';
}