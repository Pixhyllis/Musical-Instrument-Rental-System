#include "CoreClasses.h"
#include <vector>
#include <iostream>
using namespace std;

// --------------------------------INSTRUMENTS-----------------------------------

Instrument::Instrument(string name, string brand, string model, string instrumentID, double rentPerDay, bool isAvailable){
    this->name = name;
    this->brand = brand;
    this->model = model;
    this->instrumentID = instrumentID;
    this->rentPerDay = rentPerDay;
    this->isAvailable = isAvailable;
}

Instrument::~Instrument(){
}

string Instrument::getName() const{
    return name;
}

string Instrument::getBrand() const{
    return brand;
}

string Instrument::getModel() const{
    return model;
}

string Instrument::getInstrumentID() const{
    return instrumentID;
}

double Instrument::getRentPerDay() const{
    return rentPerDay;
}

bool Instrument::getIsAvailable() const{
    return isAvailable;
}

void Instrument::setName(string name){
    this->name = name;
}

void Instrument::setBrand(string brand){
    this->brand = brand;
}

void Instrument::setModel(string model){
    this->model = model;
}

void Instrument::setInstrumentID(string instrumentID){
    this->instrumentID = instrumentID;
}

void Instrument::setRentPerDay(double rentPerDay){
    this->rentPerDay = rentPerDay;
}

void Instrument::setIsAvailable(bool isAvailable)
{
    this->isAvailable = isAvailable;
}

// --------------------------- CUSTOMERS ----------------------------
Customer::Customer(string name, string customerID, string email, string contactNumber){
    this->name = name;
    this->customerID = customerID;
    this->email = email;
    this->contactNumber = contactNumber;
}


Customer::~Customer(){
}

string Customer::getName() const{
    return name;
}

string Customer::getCustomerID() const{
    return customerID;
}

string Customer::getEmail() const{
    return email;
}

string Customer::getContactNumber() const{
    return contactNumber;
}

void Customer::setName(string name){
    this->name = name;
}

void Customer::setCustomerID(string customerID){
    this->customerID = customerID;
}

void Customer::setEmail(string email){
    this->email = email;
}

void Customer::setContactNumber(string contactNumber){
    this->contactNumber = contactNumber;
}

Rental::Rental(int rentalDays, double totalCost, string instrumentID, string rentalID, string customerID){
    this->rentalDays = rentalDays;
    this->totalCost = totalCost;
    this->instrumentID = instrumentID;
    this->rentalID = rentalID;
    this->customerID = customerID;
}

Rental::~Rental(){
}

int Rental::getRentalDays() const{
    return rentalDays;
}

double Rental::getTotalCost() const{
    return totalCost;
}

string Rental::getInstrumentID() const{
    return instrumentID;
}

string Rental::getRentalID() const{
    return rentalID;
}

string Rental::getCustomerID() const{
    return customerID;
}

void Rental::setRentalDays(int rentalDays){
    this->rentalDays = rentalDays;
}

void Rental::setTotalCost(double totalCost){
    this->totalCost = totalCost;
}

void Rental::setInstrumentID(string instrumentID){
    this->instrumentID = instrumentID;
}

void Rental::setRentalID(string rentalID){
    this->rentalID = rentalID;
}

void Rental::setCustomerID(string customerID){
    this->customerID = customerID;
}

// ------------------------- SystemManager ---------------------------------

void SystemManager::displayAvailableInstruments(){
    bool found = false;
    for (const Instrument& instrument : instruments){
        if (instrument.getIsAvailable()){
            found = true;
            cout << "Instrument ID: " << instrument.getInstrumentID() << endl;
            cout << "Name: " << instrument.getName() << endl;
            cout << "Brand: " << instrument.getBrand() << endl;
            cout << "Rent per day: " << instrument.getRentPerDay() << endl;
            cout << endl;
        }
    }
    if(!found){
        cout << "No available instrument found." << endl;
    }
}

void SystemManager::displayAllRentals(){
}

void SystemManager::rentInstrument(string customerID, string instrumentID, int rentalDays){

}

void SystemManager::returnInstrument(string instrumentID)
{
}

void SystemManager::addInstrument(){
    string name, brand, model;
    double rentPerDay;
    bool isAvailable = true;

    cout << "Enter instrument name: ";
    cin >> name;
    cout << "Enter instrument brand: ";
    cin >> brand;
    cout << "Enter Instrument model: ";
    cin >> model;
    cout << "Enter rent per day: ";
    cin >> rentPerDay;

    string newID = generateID(INSTRUMENT_PREFIX);

    Instrument newInstrument(name, brand, model, newID, rentPerDay, isAvailable);
    instruments.push_back(newInstrument);

    cout << "Instrument added with the ID of '" << newID << "'" << endl;
}

string SystemManager::generateID(string prefix){
    static int instrumentCounter = 0;
    static int customerCounter = 0;
    static int rentalCounter = 0;

    string id = prefix;
    if(prefix == INSTRUMENT_PREFIX){
        instrumentCounter++;
        id += to_string(instrumentCounter);
    }else if(prefix == CUSTOMER_PREFIX){
        customerCounter++;
        id += to_string(customerCounter);
    }else if(prefix == RENTAL_PREFIX){
        rentalCounter++;
        id += to_string(rentalCounter);
    }
    return id;
}

void SystemManager::addCustomer(const Customer& newCustomer){
    customers.push_back(newCustomer);
}

string SystemManager::updateCustomerInfo()
{
return "";
}

double SystemManager::applyDiscount()
{
return 0;
}

double SystemManager::calculateTotalCost(double rentPerDay, int rentalDays){
    return 0;
}

double SystemManager::calculateOverdueFee(double rentPerDay, int rentalDays){
    return 0;
}

bool SystemManager::isOverdue(){
    return false;
}

void SystemManager::setReturnDate(){
}

void SystemManager::displayRentalInfo(){

}
