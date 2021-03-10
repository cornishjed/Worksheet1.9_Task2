#include "ListItem.h"

listItem::listItem(Bunny val, listItem* nextItem)
{
	setNext(nextItem);
}

void listItem::setNext(listItem* listItem)
{
	this->nextListItem = listItem;
}

listItem* listItem::getNext()
{
	if (nextListItem != NULL)
		return this->nextListItem;
	else
		return 0;
}

Bunny listItem::getValue()
{
	return this->dataValue;
}

void listItem::setValue(Bunny newVal)
{
	this->dataValue = newVal;
}