#include "Entity.h"

void Entity::copy(const Entity& other)
{
	setDescription(other.description);
	setEntryDate(other.entryDate);
	setQuantity(other.quantity);
}

Entity::Entity()
{
	quantity = 0;
}

Entity::Entity(const Entity& other)
{
	copy(other);
}

Entity& Entity::operator=(const Entity& other)
{
	if (this != &other)
	{
		setDescription(other.description);
		setEntryDate(other.entryDate);
		setQuantity(other.quantity);
	}

	return *this;
}

Entity::~Entity()
{
	quantity = 0;
}

void Entity::setDescription(const String& description) {
	this->description = description;
}

void Entity::setEntryDate(const DateTime& entryDate) {
	this->entryDate = entryDate;
}

void Entity::setEntryDate(const char* entryDate) {

	this->entryDate = DateTime(entryDate);
}

void Entity::setQuantity(const int quantity) {
	this->quantity = quantity;
}

String Entity::getDescription() const {
	return this->description;
}

DateTime& Entity::getEntryDate() {
	return this->entryDate;
}

int Entity::getQuantity() const {
	return this->quantity;
}