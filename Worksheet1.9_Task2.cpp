#include "Simulation.h"

int main()
{
	Simulation sim;

	sim.run();

	return 0;
}













































/*bool randGender(int, int);

int main()
{
	srand(time(0));

	string names[] = { "Fluffy", "Cuddles", "Spike", "Charles", "Weston", "Light", "Spot", "Branston", "Red", "Jupiter" };
	string colours[] = { "white", "brown", "black", "spotted" };
	int randName;
	int randColour;
	char gender;
	int randAge;

	Bunny *first = { 0 };
	Bunny *current = { 0 };
	Bunny *next = { 0 };
	Bunny *temp = { 0 };
	Bunny *prev = { 0 };

	// Create initial list
	cout << "INITIAL 5 BUNNIES" << endl;
	for (int x = 0; x < 5; x++) {
		if (x == 0) {
			randName = rand() % 10;
			randAge = rand() % 11;
			gender = randGender(randName, randAge);
			randColour = rand() % 4;
			first = new Bunny(names[randName], randAge, gender, colours[randColour], next);
			current = first;
			cout << "Name: " << first->getName() << ", Age: " << first->getAge() << ", Gender: " << first->getGender() << ", Colour: " << first->getColour() << endl;
		}
		else {
			randName = rand() % 10;
			randAge = rand() % 11;
			gender = randGender(randName, randAge);
			randColour = rand() % 4;
			next = new Bunny(names[randName], 10, gender, colours[randColour], next);
			cout << "Name: " << next->getName() << ", Age: " << next->getAge() << ", Gender: " << next->getGender() << ", Colour: " << next->getColour() << endl;
			current->setNextBunny(next);
			current = next;
		}
	}

	cout << "-----------------------------------------------------------------------" << endl;

	int bunnyCount = 5;

	current = first;

	while (bunnyCount != 1) {
		// check age
		if (current->getAge() == 10) {
			prev->setNextBunny(current->getNextBunny());
			free(current);
			current = prev->getNextBunny();
			bunnyCount--;
		}
		else {
			prev = current;
			current = prev->getNextBunny();
			}
	}


	// free memory
	current = first;

	for (int x = 0; x < bunnyCount; x++) {
		temp = current->getNextBunny();
		delete current;
		current = temp;
	}

}

bool randGender(int a, int b)
{
	if (a == 0)
		a++;

	if (b == 0)
		b++;

	if (a % b == 0)
		return 'M';
	else
		return 'F';
}*/