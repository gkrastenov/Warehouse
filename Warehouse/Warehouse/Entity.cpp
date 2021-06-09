#include "Entity.h"

void Entity::copy(const Entity& other)
{
	setDescription(other.description);
	setEntryDate(other.entryDate);
	setQuantity(other.quantity);
}

Entity::Entity()
{
	description = nullptr;
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
		delete[] description;

		setDescription(other.description);
		setEntryDate(other.entryDate);
		setQuantity(other.quantity);
	}

	return *this;
}

Entity::~Entity()
{
	delete[] description;

	description = nullptr;
	quantity = 0;
}

void Entity::setDescription(const char* description) {
	size_t lengthDescription = strlen(description) + 1;
	this->description = new char[lengthDescription];
	strcpy_s(this->description, lengthDescription, description);
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

char* Entity::getDescription() const {
	return this->description;
}

DateTime& Entity::getEntryDate() {
	return this->entryDate;
}

int Entity::getQuantity() const {
	return this->quantity;
}