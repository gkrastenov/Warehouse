#include "Change.h"

bool Change::setChangeType(const int type)
{
    if (type == 0)
    {
        this->type = ChangeType::Add;
        return true;
    }
    if (type == 1)
    {
        this->type = ChangeType::Remove;
        return true;
    }

    if (type)
    {
        this->type = ChangeType::Clean;
        return true;
    }

    this->type = ChangeType::Undefined;
    return false;
}

void Change::setChangeType(const ChangeType type)
{
    this->type = type;
}

ChangeType Change::getChangeType() const
{
    return this->type;
}

Change::Change()
{
    this->type = ChangeType::Undefined;
}

Change::Change(const String& description, const int quantity, const DateTime& date, const ChangeType type)
{
    setDescription(description);
    setQuantity(quantity);
    setEntryDate(date);
    setChangeType(type);
}

Change::~Change()
{
}

int Change::changeTypeToInt(const ChangeType type) const
{
    switch (type)
    {
    case ChangeType::Add:
        return 0;
        break;

    case ChangeType::Remove:
        return 1;

        break;
    case ChangeType::Clean:
        return 2;
        break;

    default:
        return 3;
        break;
    }
    return 3;
}

void Change::printChangeType(const ChangeType type) const
{
    switch (type)
    {
    case ChangeType::Add:
        std::cout << "Add" << std::endl;
        break;

    case ChangeType::Remove:
        std::cout << "Remove" << std::endl;
        break;

    case ChangeType::Clean:
        std::cout << "Clean" << std::endl;
        break;

    default:
        std::cout << "Undefined" << std::endl;
        break;
    }
}

void Change::print()
{
    std::cout << "Description : " << this->getDescription() << std::endl;

    DateTime currDate = this->getEntryDate();
    std::cout << "EntryDate: ";
    std::cout << currDate << std::endl;

    std::cout << "ChangeType : ";
    this->printChangeType(this->getChangeType());

    std::cout << "Quantity : ";
    std::cout << this->getQuantity() << std::endl;
}