
#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H
#include <iostream>
#include <string>
using namespace std;

//CORE CLASSES
class Instruments
{
private:
    string name;
    string brand;
    string model;
    string instrumentID;
    double rentPerDay;
    bool isAvailable;

public:
    Instruments(/* args */);
    ~Instruments();
};

class Customers
{
private:
    string name;
    string customerID;
    string email;
    int contactNumber;
public:
    Customers();
    ~Customers();
};

class Rental
{
private:
    int rentalDays;
    int totalCost;
    string instrumentID;
    string rentalID;
    string customerID;
public:
    Rental();
    ~Rental();
};


#endif