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

Change::~Change()
{

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
    std::cout << currDate.getYear() << '/' << currDate.getMonth() << '/'
        << currDate.getDay() << std::endl;

    std::cout << "ChangeType : ";
    this->printChangeType(this->getChangeType());

    std::cout << "Quantity : ";
    std::cout << this->getQuantity() << std::endl;
}
