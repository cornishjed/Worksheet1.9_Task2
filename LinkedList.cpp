#include "LinkedList.h"

linkedList::linkedList()
{
	head = NULL;
	femaleCount = 0;
	bunnyCount = 0;
}

linkedList::~linkedList()
{
	listItem* current = head;
	listItem* previous = NULL;

	while (bunnyCount != 0) {
		remove(current, previous);
		bunnyCount--;
	}
}

void linkedList::print()
{
	listItem* current = head;
	listItem* previous = NULL;
	Bunny currentItem;

	for (int age = 10; age >= 0; age--) {
		current = head;
		previous = NULL;
		for (int x = bunnyCount; x > 0; x) {
			currentItem = current->getValue();
			if (age == currentItem.getAge()) {
				currentItem.printDetails();
				x--;
			}
			if (current->getNext() == NULL)
				break;
			else
				current = current->getNext();
		}
	}

	cout << "\nBunny population: " << bunnyCount << endl;
}

void linkedList::insert(Bunny val)
{
	listItem* newItem = new listItem(val, NULL);
	newItem->setValue(val);
	newItem->setNext(head); // head is the first item in the list
	head = newItem;
}

void linkedList::incrementAge()
{
	listItem* current = head;
	listItem* previous = NULL;
	Bunny currentItem;

	for (int x = bunnyCount; x > 0; x--) {
		currentItem = current->getValue();
		currentItem.setAge(currentItem.getAge() + 1);
		current->setValue(currentItem);
		if (current->getNext() == NULL)
			break;
		else
			current = current->getNext();
	}
}

void linkedList::resetBirthCheck()
{
	listItem* current = head;
	listItem* previous = NULL;
	Bunny currentItem;

	for (int x = bunnyCount; x > 0; x--) {
		currentItem = current->getValue();
		currentItem.setBirthCheck(false);
		current->setValue(currentItem);
		if (current->getNext() == NULL)
			break;
		else
			current = current->getNext();
	}
}

void linkedList::checkAge()
{
	listItem* current = head;
	listItem* previous = NULL;
	Bunny currentItem;
	int died = 0;

	for (int x = bunnyCount; x >= 0; x--) {
		if (current == NULL)
			break;
		currentItem = current->getValue();
		if (currentItem.getAge() > 10) {
			remove(current, previous);
			bunnyCount--;
			died++;
		}
		else {
			previous = current;
			current = current->getNext();
		}
	}

	cout << "Bunnies died of old age: " << died << endl;
}

void linkedList::reproduction()
{
	Bunny mum;
	Bunny child;
	int born = 0;

	if (checkMale() == 'M') {
		checkFemale();
		while (femaleCount > 0) {
			mum = mother();
			child = child.createBunny();
			child.setAge(0);
			child.setColour(mum.getColour());
			insert(child);
			bunnyCount++;
			born++;
			femaleCount--;
		}
	}

	cout << "Bunnies born: " << born << endl;
}

void linkedList::starvation()
{
	listItem* current = head;
	listItem* previous = NULL;
	int rand1;
	int died = 0;
	
	while (died != 50) {
		for (int x = bunnyCount; x > 0; x--) {
			if (died >= 50)
				break;
			rand1 = rand() % 10;
			Bunny currentItem = current->getValue();
			if (rand1 % 2 == 0) {
				remove(current, previous);
				died++;
			}
		}
	}

	current = head;
	previous = NULL;

	bunnyCount -= 50;
	cout << "With the growing population, food became scarce. 50 bunnies died in starvation." << endl;
	cout << bunnyCount << " remain" << endl;
	cout << "*********************************************************************" << endl;
}

void linkedList::setBunnyCount(int n)
{
	bunnyCount = n;
}

int linkedList::getBunnyCount()
{
	return bunnyCount;
}

void linkedList::remove(listItem* &c, listItem* &p) // pass by reference from where remove was called, so they weren't copied into this function
{
	if (p == NULL) {
		listItem* temp = c;
		c = c->getNext();
		head = c;
		delete temp;
	}
	else {
		p->setNext(c->getNext());
		delete c;
		c = p->getNext();
	}
}

char linkedList::checkMale()
{
	listItem* current = head;
	listItem* previous = NULL;
	Bunny currentItem;

	while (current != NULL) {
		currentItem = current->getValue();
		if (currentItem.getGender() == 'M')
			return 'M';
		current = current->getNext();
	}
}

int linkedList::checkFemale()
{
	listItem* current = head;
	listItem* previous = NULL;
	Bunny currentItem;

	while (current != NULL) {
		currentItem = current->getValue();
		if (currentItem.getGender() == 'F')
			femaleCount++;
		current = current->getNext();
	}

	return femaleCount;
}

Bunny linkedList::mother()
{
	listItem* current = head;
	listItem* previous = NULL;
	Bunny currentItem;

	while (current != NULL) {
		currentItem = current->getValue();
		if ((currentItem.getGender() == 'F') && (currentItem.getBirthCheck() != true) && (currentItem.getAge() > 0)) {
			currentItem.setBirthCheck(true);
			current->setValue(currentItem);
			return currentItem;
		}
		current = current->getNext();
	}
}