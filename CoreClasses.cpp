#include "CoreClasses.h"

// Instrument

Instrument::Instrument(
string name,
string brand,
string model,
string instrumentID,
double rentPerDay,
bool isAvailable
)
{
    this->name = name;
    this->brand = brand;
    this->model = model;
    this->instrumentID = instrumentID;
    this->rentPerDay = rentPerDay;
    this->isAvailable = isAvailable;
}

Instrument::~Instrument()
{
}

string Instrument::getName()
{
    return name;
}

string Instrument::getBrand()
{
    return brand;
}

string Instrument::getModel()
{
    return model;
}

string Instrument::getInstrumentID()
{
    return instrumentID;
}

double Instrument::getRentPerDay()
{
    return rentPerDay;
}

bool Instrument::getIsAvailable()
{
    return isAvailable;
}

void Instrument::setName(string name)
{
    this->name = name;
}

void Instrument::setBrand(string brand)
{
    this->brand = brand;
}

void Instrument::setModel(string model)
{
    this->model = model;
}

void Instrument::setInstrumentID(string instrumentID)
{
    this->instrumentID = instrumentID;
}

void Instrument::setRentPerDay(double rentPerDay)
{
    this->rentPerDay = rentPerDay;
}

void Instrument::setIsAvailable(bool isAvailable)
{
    this->isAvailable = isAvailable;
}

// customer is always right
Customer::Customer(
string name,
string customerID,
string email,
string contactNumber
)
{
}

Customer::~Customer()
{
}

string Customer::getName()
{
return name;
}

string Customer::getCustomerID()
{
return customerID;
}

string Customer::getEmail()
{
return email;
}

string Customer::getContactNumber()
{
return contactNumber;
}

void Customer::setName(string name)
{
  this->name = name;
}

void Customer::setCustomerID(string customerID)
{
  this->customerID = customerID;
}

void Customer::setEmail(string email)
{
  this->email = email;
}

void Customer::setContactNumber(string contactNumber)
{
  this->contactNumber = contactNumber;
}

Rental::~Rental()
{
}

int Rental::getRentalDays()
{
return 0;
}

double Rental::getTotalCost()
{
return 0;
}

string Rental::getInstrumentID()
{
return "";
}

string Rental::getRentalID()
{
return "";
}

string Rental::getCustomerID()
{
return "";
}

void Rental::setRentalDays(int rentalDays)
{
}

void Rental::setTotalCost(double totalCost)
{
}

void Rental::setInstrumentID(string instrumentID)
{
}

void Rental::setRentalID(string rentalID)
{
}

void Rental::setCustomerID(string customerID)
{
}

// SystemManager

void SystemManager::displayAvailableInstruments()
{
}

void SystemManager::displayAllRentals()
{
}

void SystemManager::rentInstrument(
string customerID,
string instrumentID,
int rentalDays
)
{
}

void SystemManager::returnInstrument(string instrumentID)
{
}

string SystemManager::addInstrument()
{
return "";
}

string SystemManager::generateID(string prefix)
{
return "";
}

string SystemManager::addCustomer()
{
return "";
}

string SystemManager::updateCustomerInfo()
{
return "";
}

double SystemManager::applyDiscount()
{
return 0;
}

double SystemManager::calculateTotalCost(
double rentPerDay,
int rentalDays
)
{
return 0;
}

double SystemManager::calculateOverdueFee(
double rentPerDay,
int rentalDays
)
{
return 0;
}

bool SystemManager::isOverdue()
{
return false;
}

void SystemManager::setReturnDate()
{
}
