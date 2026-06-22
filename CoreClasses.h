// Header file containing the coreclasses
#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//PREFIXES FOR GENERATEID()
const string INSTRUMENT_PREFIX = "INST";
const string CUSTOMER_PREFIX = "CUST";
const string RENTAL_PREFIX = "RENT";

//CORE CLASSES
class Instrument
{
private:
    string name;
    string brand;
    string model;
    string instrumentID;
    double rentPerDay;
    bool isAvailable;

public:
    Instrument(
        string name,
        string brand,
        string model,
        string instrumentID,
        double rentPerDay,
        bool isAvailable
    );
    ~Instrument();
    string getName();
    string getBrand();
    string getModel();
    string getInstrumentID();
    double getRentPerDay();
    bool getIsAvailable();
    void setName(string name);
    void setBrand(string brand);
    void setModel(string model);
    void setInstrumentID(string instrumentID);
    void setRentPerDay(double rentPerDay);
    void setIsAvailable(bool isAvailable);

};

class Customer
{
private:
    string name;
    string customerID;
    string email;
    string contactNumber;
public:
    Customer(
        string name,
        string customerID,
        string email,
        string contactNumber    
    );
    ~Customer();
    string getName();
    string getCustomerID();
    string getEmail();
    string getContactNumber();
    void setName(string name);
    void setCustomerID(string customerID);
    void setEmail(string email);
    void setContactNumber(string contactNumber);

    
};

class Rental
{
private:
    int rentalDays;
    double totalCost;
    string instrumentID;
    string rentalID;
    string customerID;
public:
    Rental(
        int rentalDays,
        double totalCost,
        string instrumentID,
        string rentalID,
        string customerID
    );
    ~Rental();
    int getRentalDays();
    double getTotalCost();
    string getInstrumentID();
    string getRentalID();
    string getCustomerID();
    void setRentalDays(int rentalDays);
    void setTotalCost(double totalCost);
    void setInstrumentID(string instrumentID);
    void setRentalID(string rentalID);
    void setCustomerID(string customerID);

};

class SystemManager
{
private:
    vector<Instrument> instruments;
    vector<Customer> customers;
    vector<Rental> rentals;
public:
    void displayAvailableInstruments();
    void displayAllRentals();
    void rentInstrument(string customerID, string instrumentID, int rentalDays);
    void returnInstrument(string instrumentID);
    string addInstrument();
    string generateID(string prefix);
    string addCustomer();
    string updateCustomerInfo();
    double applyDiscount();
    double calculateTotalCost(double rentPerDay, int rentalDays);
    double calculateOverdueFee(double rentPerDay, int rentalDays);
    bool isOverdue();
    void setReturnDate();
    void displayRentalInfo();
};
#endif