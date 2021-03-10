#ifndef LISTITEM_H
#define LISTITEM_H
#include "Bunny.h"

class listItem
{
public:
	listItem(Bunny val, listItem* nextItem);
	void setNext(listItem* listItem);
	listItem* getNext();
	Bunny getValue();
	void setValue(Bunny newValue);

private:
	Bunny dataValue;
	listItem* nextListItem = '\0';
};

#endif