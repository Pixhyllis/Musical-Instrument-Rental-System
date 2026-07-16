// Header file containing the coreclasses
#ifndef CORECLASSES_H
#define CORECLASSES_H
#include <iostream>
#include <string>
#include <list>
#include <fstream>


using namespace std;

//PREFIXES FOR GENERATEID()
const string INSTRUMENT_PREFIX = "INST";
const string CUSTOMER_PREFIX = "CUST";
const string RENTAL_PREFIX = "RENT";
const string WAITING_PREFIX = "WAIT";



//STRUCTURE FOR WAITING QUEUE
struct WaitingRequest
{
    string queueID;
    string customerID;
    string customerName;
    string instrumentID;
    string instrumentName;
    string requestDate;
};

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
    string getName() const;
    string getBrand() const;
    string getModel() const;
    string getInstrumentID() const;
    double getRentPerDay() const;
    bool getIsAvailable() const; 
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
    string getName() const;
    string getCustomerID() const;
    string getEmail() const;
    string getContactNumber() const;
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
    bool isCompleted;
    string instrumentID;
    string rentalID;
    string customerID;
    string rentalDate;
    string returnDate;
public:
    Rental(
        int rentalDays,
        double totalCost,
        bool isCompleted,
        string instrumentID,
        string rentalID,
        string customerID,
        string rentalDate,
        string returnDate
    );
    ~Rental();
    int getRentalDays() const;
    double getTotalCost() const;
    bool getIsCompleted() const;
    string getInstrumentID() const;
    string getRentalID() const;
    string getCustomerID() const;
    string getRentalDate() const;
    string getReturnDate() const;
    void setRentalDays(int rentalDays);
    void setTotalCost(double totalCost);
    void setInstrumentID(string instrumentID);
    void setRentalID(string rentalID);
    void setCustomerID(string customerID);
    void setRentalDate(string rentalDate);
    void setReturnDate(string returnDate);
    void setIsCompleted(bool isCompleted);


};

class SystemManager
{
private:
    list<Instrument> instruments;
    list<Customer> customers;
    list<Rental> rentals;
    list<WaitingRequest> waitingQueue;
    int instrumentCounter = 0;
    int customerCounter = 0;
    int rentalCounter = 0;
    int waitingCounter = 0;

public:
    void saveData(); 
    void loadData(); 
    void displayAvailableInstruments();
    void displayAllInstruments();
    void displayInstrument(const Instrument& instruments);
    void displayAllRentals();
    void rentInstrument();
    void returnInstrument();
    void addInstrument();
    void addCustomer();
    string generateID(string prefix);
    string getCurrentDate();
    void updateCustomerInfo();
    int calculateOverdueDays(const Rental& rental);
    double applyDiscount(double rentPerDay, int rentalDays);
    double calculateBaseCost(double rentPerDay, int rentalDays);
    double applyOverdueFee(double rentPerDay, int rentalDays);
    bool isOverdue(const Rental& rental);
    void setReturnDate(Rental& rental, int rentalDays);
    void displayRentalInfo(const Rental& rental);
    void searchInstrumentByBrand();
    void searchInstrumentByModel();
    void displayWhoRentedWhat();
    void sortInstrumentsByPrice(); 
    void displayWaitingQueue();
    void enqueueWaitingCustomer(const string& customerID, const string& customerName, const string& instrumentID, const string& instrumentName);
    void processWaitingQueueForInstrument(const string& instrumentID);
    void displayMenu();
};


#endif