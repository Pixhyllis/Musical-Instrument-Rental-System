#include "CoreClasses.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

// TODO: if no valid customer id, deny renting
// TODO: if no instruments available, say so
// TODO: if no valid rentIds, deny returning
// TODO: user must enter valid credentials when registering customer


// --------------------------------INSTRUMENTS-----------------------------------


// Instrument class constructors, getters, setters, and deconstructors - The following block of code is the implementation of the Instrument class. It includes the constructor, destructor, getter and setter methods for the private member variables of the class. The constructor initializes the member variables with the values passed as parameters. The destructor is used to free up any resources that were allocated for the object. The getter methods return the value of the private member variable, while the setter methods assign a new value to the private member variable.
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

// Customers class constructors, getters, setters, and deconstructors - The following block of code is the implementation of the Instrument class. It includes the constructor, destructor, getter and setter methods for the private member variables of the class. The constructor initializes the member variables with the values passed as parameters. The destructor is used to free up any resources that were allocated for the object. The getter methods return the value of the private member variable, while the setter methods assign a new value to the private member variable.
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

// --------------------------- RENTAL ----------------------------

// Rental class constructors, getters, setters, and deconstructors - The following block of code is the implementation of the Instrument class. It includes the constructor, destructor, getter and setter methods for the private member variables of the class. The constructor initializes the member variables with the values passed as parameters. The destructor is used to free up any resources that were allocated for the object. The getter methods return the value of the private member variable, while the setter methods assign a new value to the private member variable.

Rental::Rental(int rentalDays, double totalCost, bool isCompleted, string instrumentID, string rentalID, string customerID, string rentalDate, string returnDate){
    this->rentalDays = rentalDays;
    this->totalCost = totalCost;
    this->instrumentID = instrumentID;
    this->rentalID = rentalID;
    this->customerID = customerID;
    this->rentalDate = rentalDate;
    this->returnDate = returnDate;
    this->isCompleted = isCompleted;
    
}

Rental::~Rental(){
}

int Rental::getRentalDays() const{
    return rentalDays;
}

double Rental::getTotalCost() const{
    return totalCost;
}

bool Rental::getIsCompleted() const{
    return isCompleted;
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

string Rental::getRentalDate() const{
    return rentalDate;
}

string Rental::getReturnDate() const{
    return returnDate;
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

void Rental::setRentalDate(string rentalDate){
    this->rentalDate = rentalDate;
}

void Rental::setReturnDate(string returnDate){
    this->returnDate = returnDate;
}

void Rental::setIsCompleted(bool isCompleted){
    this->isCompleted = isCompleted;
}

// ------------------------- SystemManager ---------------------------------

// saveData() function - It saves system data which includes instrument, customer, rental, and waiting queue data to their respective text files. It opens each file in write mode, iterates through the corresponding list of objects, and writes their data to the file in a specific format. After writing all the data, it closes the file.
void SystemManager::saveData(){
    ofstream myInsData("InsData.txt");
    if (myInsData.is_open()){ 
        for(const auto& instrument : instruments){
            myInsData   << instrument.getName() << "|"
                        << instrument.getBrand() << "|"
                        << instrument.getModel() << "|"
                        << instrument.getInstrumentID() << "|"
                        << instrument.getRentPerDay() << "|"
                        << instrument.getIsAvailable() << endl;
        };
    }
    myInsData.close();

    ofstream myCustData("CustData.txt");
    if (myCustData.is_open()){ 
        for(const auto& customer : customers){
            myCustData  << customer.getName() << "|"
                        << customer.getCustomerID()<< "|"
                        << customer.getEmail() << "|"
                        << customer.getContactNumber() << endl;
        };
    }
    myCustData.close();
    
    ofstream myRentData("RentData.txt");
    if(myRentData.is_open()){
        for (const auto& rental : rentals){
            myRentData << rental.getRentalDays() << "|" 
                       << rental.getTotalCost() << "|"
                       << rental.getIsCompleted() << "|"
                       << rental.getInstrumentID() << "|"
                       << rental.getRentalID() << "|"
                       << rental.getCustomerID() << "|"
                       << rental.getRentalDate() << "|"
                       << rental.getReturnDate() << endl;
        }
    }
    myRentData.close();

    ofstream myQueueData("QueueData.txt");
    if(myQueueData.is_open()){
        for(const auto& request:waitingQueue){
            myQueueData << request.queueID << "|" 
                        << request.customerID << "|" 
                        << request.customerName << "|" 
                        << request.instrumentID << "|" 
                        << request.instrumentName << "|" 
                        << request.requestDate << endl;
        }
    }
    myQueueData.close();

}


// loadData() function - It loads system data from text files into the system. It opens each file in read mode, reads the data line by line, and creates corresponding objects (Instrument, Customer, Rental, WaitingRequest) with the read data. It also updates the counters for instruments, customers, rentals, and waiting requests based on the loaded data. If a file is not found, it initializes the corresponding list as empty.
void SystemManager::loadData(){
    cout << "__________________________________________________" << endl;
    ifstream myInsData("InsData.txt");  
        if(myInsData.is_open()){

            instruments.clear();
            cout << "Loading Instruments Data... " << endl;
            string name, brand, model, ID, RentStr, AvailableStr; 

            while(getline(myInsData, name, '|')){
                  getline(myInsData, brand, '|');
                  getline(myInsData, model, '|');
                  getline(myInsData, ID, '|');
                  getline(myInsData, RentStr, '|');
                  getline(myInsData, AvailableStr);

                double rent = stod(RentStr);
                bool available = (AvailableStr == "1");

                Instrument instrument(name, brand, model, ID, rent, available);

                instruments.push_back(instrument);
            
                if(ID.rfind(INSTRUMENT_PREFIX, 0) == 0){ //if it finds INST, it will return 0
                    int number = stoi(ID.substr(INSTRUMENT_PREFIX.size()));  //INSTRUMENT_PREFIX.size = 4 INST= 4 characters. Therefore, number == index 4 of the ID
                    if(number > instrumentCounter){
                        instrumentCounter = number;
                    }                                  
                }
            }
    }else{
        cout << "No Instruments data found... Starting with an empty data " << endl;
    }
    
    myInsData.close();

    ifstream myCustData("CustData.txt");
        if(myCustData.is_open()){

            customers.clear();
            
            cout << "Loading Customers Data... " << endl;

            string name, customerID, email, contactNumber;

            while(getline(myCustData, name, '|')){
                getline(myCustData, customerID, '|');
                getline(myCustData, email, '|');
                getline(myCustData, contactNumber);
            
                Customer customer(name, customerID, email, contactNumber);

                customers.push_back(customer);

                if(customerID.rfind(CUSTOMER_PREFIX, 0) == 0){
                    int number = stoi(customerID.substr(CUSTOMER_PREFIX.size()));
                        if(number > customerCounter){
                        customerCounter = number;
                        }
                }
            }
        }else{
            cout << "No Customers data found... Starting with an empty data " << endl;
        }

        myCustData.close();

    ifstream myRentData("RentData.txt");

        if(myRentData.is_open()){
            rentals.clear();

            cout << "Loading Rentals Data... " << endl;

            string RentDaysStr, TotalCostStr, CompleteStr, InstID, RentID, CustID, RentDate, ReturnDate;

            while(getline(myRentData, RentDaysStr, '|')){
                  getline(myRentData, TotalCostStr, '|');
                  getline(myRentData, CompleteStr, '|');
                  getline(myRentData, InstID, '|');
                  getline(myRentData, RentID, '|');
                  getline(myRentData, CustID, '|');
                  getline(myRentData, RentDate, '|');
                  getline(myRentData, ReturnDate);

                int RentalDays = stoi(RentDaysStr);
                double TotalCost = stod(TotalCostStr);
                bool IsCompleted = (CompleteStr=="1");

                Rental rental(RentalDays, TotalCost, IsCompleted, InstID, RentID, CustID, RentDate, ReturnDate);

                rentals.push_back(rental);

                if(RentID.rfind(RENTAL_PREFIX, 0) == 0){
                    int number = stoi(RentID.substr(RENTAL_PREFIX.size()));
                    if(number > rentalCounter){
                        rentalCounter = number;
                    }
                }
            }
        }else{
            cout << "No Rentals data found... Starting with an empty data " << endl;
        }
    
    myRentData.close();

    ifstream myQueueData("QueueData.txt");

        if (myQueueData.is_open()){
            waitingQueue.clear();

            cout << "Loading Queue..." << endl;

            string queueID, customerID, customerName, instrumentID, instrumentName, requestDate;

            while(getline(myQueueData, queueID, '|')){
                  getline(myQueueData, customerID, '|');
                  getline(myQueueData, customerName, '|');
                  getline(myQueueData, instrumentID, '|');
                  getline(myQueueData, instrumentName, '|');
                  getline(myQueueData, requestDate);

            WaitingRequest request;
            request.queueID = queueID;
            request.customerID = customerID;
            request.customerName = customerName;
            request.instrumentID = instrumentID;
            request.instrumentName = instrumentName;
            request.requestDate = requestDate;

            waitingQueue.push_back(request);

            if(queueID.rfind(WAITING_PREFIX, 0) == 0){
                int number = stoi(queueID.substr(WAITING_PREFIX.size()));
                if(number > waitingCounter){
                    waitingCounter = number;
                }
            }
        }
    }else {
        cout << "No Queue data found... Starting with an empty data " << endl;
    }
    myQueueData.close();

    cout << endl << "NUMBER OF INSTRUMENTS: " << instruments.size() << endl;
    cout << "NUMBER OF CUSTOMERS: " << customers.size() << endl;
    cout << "NUMBER OF RENTALS: " << rentals.size() << endl;
    cout << "NUMBER OF WAITING REQUESTS: " << waitingQueue.size() << endl;
    
    cout << "__________________________________________________" << endl;
}


// enqueueWaitingCustomer() function - It adds a customer to the waiting queue for a specific instrument. It creates a WaitingRequest object with the provided customer and instrument details, generates a unique queue ID, and sets the request date to the current date. The request is then added to the waitingQueue list, and a confirmation message is displayed.
void SystemManager::enqueueWaitingCustomer(const string& customerID, const string& customerName, const string& instrumentID, const string& instrumentName){
    WaitingRequest request;
    request.queueID = generateID(WAITING_PREFIX);
    request.customerID = customerID;
    request.customerName = customerName;
    request.instrumentID = instrumentID;
    request.instrumentName = instrumentName;
    request.requestDate = getCurrentDate();

    waitingQueue.push_back(request);

    system("cls");
    cout << "------------------------------------" << endl << endl;
    cout << "Customer successfully added" << endl << "to the waiting queue." << endl << endl;
    cout << "Customer Name: " << request.customerName << endl;
    cout << "Customer ID: " << request.customerID << endl;
    cout << "Queued for: " << request.instrumentName << " (ID: " << request.instrumentID << ")" << endl;
    cout << "Queue ID: " << request.queueID << endl;
    cout << endl << "------------------------------------" << endl;
}

// displayWaitingQueue() function - It displays the current waiting queue of customers for instruments. It iterates through the waitingQueue list and prints the details of each waiting request, including queue ID, customer ID, customer name, instrument ID, instrument name, and request date. If the waiting queue is empty, it displays a message indicating that there are no waiting requests.
void SystemManager::displayWaitingQueue(){
    system("cls");
    cout << "------------------------------------" << endl;
    bool found = false;
    cout << "\t===WAITING QUEUE===\n";
    
    for(const auto& request:waitingQueue){
        found = true;
        cout << "========================================" << endl;
        cout << "Queue ID: " << request.queueID << endl;
        cout << "Customer ID: " << request.customerID << endl;
        cout << "Customer Name: " << request.customerName << endl;
        cout << "Instrument ID: " << request.instrumentID << endl;
        cout << "Instrument Name: " << request.instrumentName << endl;
        cout << "Request Date: " << request.requestDate << endl;
    } 
    if(!found){
        cout << "========================================" << endl;
        cout << "The waiting queue is empty..." << endl;
    }
    cout << "========================================" << endl;
    cout << "------------------------------------" << endl;
}

// processWaitingQueueForInstrument - This block of code assigns the next customer in queue the specific instrument they queued for
void SystemManager::processWaitingQueueForInstrument(const string& instrumentID){

    for(auto it = waitingQueue.begin(); it != waitingQueue.end();){
        if(it->instrumentID == instrumentID){
            cout << "\nNext customer for this instrument:\n" << endl;
            cout << "Customer ID: " << it->customerID << endl;
            cout << "Customer Name: " << it->customerName << endl;
            
            bool assign;
            cout << "Assign the returned instrument to this customer? (1 = Yes, 0 = No): ";
            cin >> assign;
            
            if(assign){
                int rentalDays;
                cout << "Enter rental days: ";
                cin >> rentalDays;

                double rentPerDay = 0;

                bool discountApplied = false;
                
                bool lock = 0;

                do{
                    cout << "Apply 10% discount? (1 for yes, 0 for no): ";
                    cin >> discountApplied;

                    if(cin.fail()){
                        cin.clear(); 
                        cin.ignore(10000, '\n'); 
                        system("cls");
                        cout << "_________________________________________________________________" << endl;
                        cout << "Invalid input. Please enter a valid choice." << endl;
                        cout << "_________________________________________________________________" << endl << endl;
                    }else{
                        lock = 1;
                    }
                }while(lock != 1);

                
                
                for(Instrument& instrument:instruments){
                    if(instrument.getInstrumentID() == instrumentID){
                        rentPerDay = instrument.getRentPerDay();
                        instrument.setIsAvailable(false);
                        break;
                    }
                }
            
                string rentalID = generateID(RENTAL_PREFIX);
                double totalCost = calculateBaseCost(rentPerDay, rentalDays);

                if (discountApplied) {
                    totalCost -= applyDiscount(rentPerDay, rentalDays);
                }

                Rental newRental(rentalDays, totalCost, false, instrumentID, rentalID, it->customerID, "", "");
                setReturnDate(newRental, rentalDays);
                rentals.push_back(newRental);
            
                cout << "Instruments rented to " << it->customerName << endl;
                cout << "Rental ID: " << rentalID << endl;

                system("cls");
                cout << "------------------------------------" << endl << endl;
                cout << "Rented instrument with the ID of " << rentalID << endl << endl;
                cout << "Rented By: " << it->customerName << " (ID: " << it->customerID << ")" << endl;
                cout << "Instrument name: " << it->instrumentName << " (ID: " << it->instrumentID << ")" << endl;
                cout << "Rent Date: " << it->requestDate << endl;
                cout << "Days rented: " << rentalDays << endl << endl;
                cout << "\tTOTAL COST: " << totalCost << "PHP" << endl;
                cout << "\tReturn by: " << newRental.getReturnDate() << endl << endl;
                cout << "------------------------------------" << endl;

                it = waitingQueue.erase(it);
                saveData();
                return;
            }else{
                it = waitingQueue.erase(it);
                saveData();
            }

        }else{
            ++it;
        }
        
    }

    cout << "No waiting customer for this instrument." << endl << endl;
    cout << "------------------------------------" << endl;
}

// This block of code displays all available instruments
void SystemManager::displayAvailableInstruments(){
    bool found = false;
    int displayNumber = 1;
    
    system("cls");
    cout << "------------------------------------" << endl;
    cout << endl << "\tAVAILABLE INSTRUMENTS" << endl << endl;
    for (const auto& instrument : instruments){
        if (instrument.getIsAvailable()){
            found = true;
            cout << "----------------------------------" << endl;
            cout << "INSTRUMENT NO. " << displayNumber << endl << endl;
            displayInstrument(instrument);
            displayNumber++;
        }
    }
    cout << "----------------------------------" << endl;
    if(!found){
        cout << "No available instrument found." << endl;
    }
    cout << endl << "------------------------------------" << endl << endl;
}

// This block of code displays all instruments regardless if are rented or not
void SystemManager::displayAllInstruments(){
    int displayNumber = 1;
    system("cls");
    cout << "------------------------------------" << endl;
    cout << endl << "\tALL INSTRUMENTS" << endl << endl;
    for(const Instrument& instrument:instruments){
        cout << "----------------------------------" << endl;
        cout << "Instrument No. " << displayNumber++ << endl;

        displayInstrument(instrument);

        cout << "Status: " << (instrument.getIsAvailable() ? "Available" : "Currently Rented") << endl;
        cout << "----------------------------------" << endl;
    }
    if(instruments.empty()){
        cout << "No instruments found." << endl;
    }
    cout << "------------------------------------" << endl;
}

// This block of code displays certain instrument. This block of code are called in some of the functions and it is to be iterated 
void SystemManager::displayInstrument(const Instrument& instruments){ 
    
    cout << "Instrument ID: " << instruments.getInstrumentID() << endl;
    cout << "Name: " << instruments.getName() << endl;
    cout << "Brand: " << instruments.getBrand() << endl;
    cout << "Model: " << instruments.getModel() << endl;
    cout << "Rent per day: " << instruments.getRentPerDay() << endl;
    cout << "----------------------------------" << endl;
}

// This block of code displays all rentals made
void SystemManager::displayAllRentals(){
    system("cls");
    cout << "------------------------------------" << endl;
    cout << "\tALL RENTALS" << endl << endl;
    for (const Rental& rental : rentals){
        cout << "----------------------------------" << endl;
        displayRentalInfo(rental);
        cout << "----------------------------------" << endl;
    }
    cout << "------------------------------------" << endl;
}

// This block of code allows registered customers to rent an instrument
void SystemManager::rentInstrument(){
    int userChoice, rentalDays;
    bool isCompleted = false;
    string customerID;
    string CustomerName;

    // check if customer has a valid ID, then proceed to rent
    cout << "Enter customer ID: ";
    cin >> customerID;

    // Makes the input uppercase so that it still finds the specific ID even if they typed in lowercase
    for(char& c : customerID){
        c = toupper(c);
    }

    bool customerFound = false;

    for (const Customer& customer : customers){
        if (customer.getCustomerID() == customerID ){
            customerFound = true;
            CustomerName = customer.getName();
            break;
        }
    }

    if (!customerFound)
    {
        system("cls");
        cout << "------------------------------------" << endl << endl;
        cout << "Customer ID not found." << endl << endl;
        cout << "------------------------------------" << endl << endl;
        return;
    }
    bool lock1 = 0;

    // Handles invalid input
    do{

                    displayAllInstruments();

                    cout << "Select the Instrument Number you'd like to rent: ";
                    cin >> userChoice;

                    if(cin.fail()){
                        cin.clear(); 
                        cin.ignore(10000, '\n'); 
                        system("cls");
                        cout << "_________________________________________________________________" << endl;
                        cout << "Invalid input. Please enter a valid choice." << endl;
                        cout << "_________________________________________________________________" << endl << endl;
                    }else if(userChoice <= 0){
                        system("cls");
                        cout << "------------------------------------" << endl << endl;
                        cout << "Input a valid number." << endl << endl;
                        cout << "------------------------------------" << endl << endl;
                        return;
                    }
                    else{
                        lock1 = 1;
                    }
                }while(lock1 != 1);

    auto it = instruments.begin();
    int currentNumber = 1;
    

    while(it != instruments.end()){
            if(currentNumber == userChoice){
                break;
            }
            currentNumber++;
        ++it;
    }

    if (it == instruments.end()){
        system("cls");
        cout << "------------------------------------" << endl << endl;
        cout << "Input a valid number." << endl << endl;
        cout << "------------------------------------" << endl << endl;
        return;
    }

    //If the instrument is unavailable, ask the customer if they want to join the queue.
    if(!it->getIsAvailable()){
        bool answer = false;
        cout << "This instrument is currently rented.\n";

        bool lock2 = 0;

        // Handles invalid input
        do{
                    cout << "Would you like to join the waiting queue? (1 for yes, 0 for no): ";
                    cin >> answer;

                    if(cin.fail()){
                        cin.clear(); 
                        cin.ignore(10000, '\n'); 
                        system("cls");
                        cout << "_________________________________________________________________" << endl;
                        cout << "Invalid input. Please enter a valid choice." << endl;
                        cout << "_________________________________________________________________" << endl << endl;
                    }else{
                        lock2 = 1;
                    }
                }while(lock2 != 1);

        if(answer){
            string customerName;
            
            for(const Customer& customer:customers){
                if(customer.getCustomerID() == customerID){
                    customerName = customer.getName();
                    break;
                }
            }

            enqueueWaitingCustomer(customerID, customerName, it->getInstrumentID(), it->getName());
            saveData();
        }else{
            system("cls");
            cout << "_________________________________________________________________" << endl;
            cout << "Rent Discarded" << endl;
            cout << "_________________________________________________________________" << endl << endl;
        }
        return;
    }

    
    cout << "Selected: " << it->getName() << endl;

    bool lock3 = 0;

        // Handles invalid input
        do{
                    cout << "How many days would you like to rent this instrument?: ";
    cin >> rentalDays;

                    if(cin.fail()){
                            cin.clear(); 
                            cin.ignore(10000, '\n'); 
                            system("cls");
                            cout << "_________________________________________________________________" << endl;
                            cout << "Invalid input. Please enter a valid choice." << endl;
                            cout << "_________________________________________________________________" << endl << endl;
                        }else if(rentalDays <= 0){
                            system("cls");
                            cout << "_________________________________________________________________" << endl;
                            cout << "Rental days must be greater than 0." << endl;
                            cout << "_________________________________________________________________" << endl << endl;
                        }
                        else{
                            lock3 = 1;
                        }
                     }while(lock3 != 1);

    bool discountApplied = false;
    bool lock4 = 0;

    // Handles invalid input
    do{
                    cout << "Apply 10% discount? (1 for yes, 0 for no): ";
                    cin >> discountApplied;

                    if(cin.fail()){
                        cin.clear(); 
                        cin.ignore(10000, '\n'); 
                        system("cls");
                        cout << "_________________________________________________________________" << endl;
                        cout << "Invalid input. Please enter a valid choice." << endl;
                        cout << "_________________________________________________________________" << endl << endl;
                    }else{
                        lock4 = 1;
                    }
                }while(lock4 != 1);

    it->setIsAvailable(false);

    string newID = generateID(RENTAL_PREFIX);
    double baseCost = calculateBaseCost(it->getRentPerDay(), rentalDays);
    double discountAmmount = applyDiscount(it->getRentPerDay(), rentalDays);
    double totalCost = discountApplied ? baseCost - discountAmmount : baseCost;

    Rental newRental(rentalDays, totalCost, false, it->getInstrumentID(), newID, customerID, "", "");
    setReturnDate(newRental, rentalDays);
    rentals.push_back(newRental);
    saveData();
    
    system("cls");
    cout << "------------------------------------" << endl << endl;
    cout << "Rented instrument with the ID of " << newID << endl << endl;
    cout << "Rented By: " << CustomerName << " (ID: " << customerID << ")" << endl;
    cout << "Instrument name: " << it->getName() << " (ID: " << it->getInstrumentID() << ")" << endl;
    cout << "Rent Date: " << newRental.getRentalDate() << endl;
    cout << "Days rented: " << rentalDays << endl << endl;
    cout << "\tTOTAL COST: " << totalCost << "PHP" << endl;
    cout << "\tReturn by: " << newRental.getReturnDate() << endl << endl;
    cout << "------------------------------------" << endl;
}

// This block of code lets users return an instrument. It requires an active rental
void SystemManager::returnInstrument(){
    string choice, CustomerName, InstrumentName, RentalID, InstrumentID;
    cout << "Type the rental ID you'd like to return: ";
    cin >> choice;

    for(char& c : choice){
        c = toupper(c);
    }

    // cant use range based for loops cause i need to use rental.erase to clear memory
    system("cls");
    cout << "------------------------------------" << endl;
    for (auto i = rentals.begin(); i != rentals.end(); i++){
        if (choice == i->getRentalID()){
            string instrumentId = i->getInstrumentID();
            double rentPerDay = 0;
            
            for (Instrument& instrument : instruments){
                if(instrument.getInstrumentID() == instrumentId){
                    instrument.setIsAvailable(true);
                    rentPerDay = instrument.getRentPerDay();
                    InstrumentName = instrument.getName();
                    break;
                }
            }
            
            for(Customer& customer:customers){
                if(customer.getCustomerID() == i->getCustomerID()){
                    CustomerName = customer.getName();
                    break;
                }
            }

            if(i->getIsCompleted()){
                cout << endl << "This rental has already been completed." << endl << endl;
                cout << "------------------------------------" << endl << endl;
                return;
            }

            cout << "\t === " << i->getInstrumentID() << " returned! ===" << endl;
            cout << "------------------------------------" << endl << endl;
            cout << "\tRENTAL SUMMARY" << endl;
            cout << "\tRental ID: " << i->getRentalID() << endl << endl;
            cout << "Customer: " << CustomerName << " (ID: " << i->getCustomerID() << ")" << endl;
            cout << "Instrument: " << InstrumentName << " (ID: " << i->getInstrumentID() << ")" << endl;
            cout << "Rented on: " << i->getRentalDate() << endl;
            cout << "Returned by: " << getCurrentDate() << endl;
            cout << "Days rented: " << i->getRentalDays() << endl << endl;
            cout << "Rental cost: " << i->getTotalCost() << "PHP" << endl;

            double totalCost = i->getTotalCost();
            if(isOverdue(*i)){
                double overDueFee = applyOverdueFee(rentPerDay, i->getRentalDays());
                cout << "*Overdue fee: " << overDueFee << "PHP" << endl << endl;
                cout << "\t -- TOTAL COST: " << totalCost + overDueFee << "PHP --" << endl;
                cout << "------------------------------------" << endl << endl;
            }else{
                cout << endl << "\t -- TOTAL COST: " << totalCost << "PHP --" << endl;
                cout << "Please pay at the counter. Thank You!" << endl << endl;
                cout << "------------------------------------" << endl << endl;
            }

            i->setIsCompleted(true);
            processWaitingQueueForInstrument(instrumentId);
            saveData();
            return;
        }
    }
    
    cout << endl << "Rental ID not found." << endl << endl ;
    cout << "------------------------------------" << endl << endl;
}

// This block of code adds an instrument to the instrument vector
void SystemManager::addInstrument(){
    string name, brand, model;
    double rentPerDay;
    bool isAvailable = true;

    cout << "----------------------------" << endl;
    cout << "Enter instrument name: ";
    getline(cin, name);
    cout << "Enter instrument brand: ";
    getline(cin, brand);

    for(char& c : brand) {
        c = toupper(c);
    }

    cout << "Enter Instrument model: ";
    getline(cin, model);

    bool lock = 0;
    do{
        cout << "Enter rent per day (PHP): ";
        cin >> rentPerDay;
        if(cin.fail()){
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            system("cls");
            cout << "_________________________________________________________________" << endl;
            cout << "Invalid input. Please enter a valid number." << endl;
            cout << "_________________________________________________________________" << endl << endl;
        }else if(rentPerDay <= 0){
            system("cls");
            cout << "_________________________________________________________________" << endl;
            cout << "Rent per day must be greater than 0." << endl;
            cout << "_________________________________________________________________" << endl << endl;
        }
        else{
            lock = 1;
        }
    }while(lock != 1);

    string newID = generateID(INSTRUMENT_PREFIX);
    
    Instrument newInstrument(name, brand, model, newID, rentPerDay, isAvailable);
    instruments.push_back(newInstrument);
    saveData();
    system("cls");
    cout << "------------------------------------" << endl << endl;
    cout << "Instrument added with the ID of '" << newID << "'" << endl << endl;
    cout << "Instrument name: " << name << endl;
    cout << "Instrument brand: " << brand << endl;
    cout << "Instrument model: " << model << endl;
    cout << "Instrument ID: " << newID << endl;
    cout << "Rent per day: " << rentPerDay << "PHP" << endl;
    cout << endl;
    cout << "------------------------------------" << endl;
}

// This block of codes generates a unique ID for registering instruments and customers, and as well as rentals and queue
string SystemManager::generateID(string prefix){
    if(prefix == INSTRUMENT_PREFIX){
        instrumentCounter++;
        return prefix + to_string(instrumentCounter);
    }else if(prefix == CUSTOMER_PREFIX){
        customerCounter++;
        return prefix + to_string(customerCounter);
    }else if(prefix == RENTAL_PREFIX){
        rentalCounter++;
        return prefix + to_string(rentalCounter);
    }else if(prefix == WAITING_PREFIX){
        waitingCounter++;
        return prefix + to_string(waitingCounter);
    }

    return prefix;
}

// This block of code gets the current date locally in the system
string SystemManager::getCurrentDate(){

    time_t now = time(nullptr);
    tm localTime{};

    localtime_s(&localTime, &now);  // Windows version

    stringstream ss;
    ss << put_time(&localTime, "%Y-%m-%d");
    return ss.str();
}

// This block of code registers a customer
void SystemManager::addCustomer(){
    string name, customerID, email, contactNumber;  

    cout << "------------------------------" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your email address: ";
    getline(cin, email);
    cout << "Enter your contact number: ";
    getline(cin, contactNumber);

    string newID = generateID(CUSTOMER_PREFIX);
    Customer newCustomer(name, newID, email, contactNumber);
    customers.push_back(newCustomer);
    saveData();

    system("cls");
    cout << "------------------------------------" << endl << endl;
    cout << "Added customer with the ID of '" << newID << "'" << endl << endl;
    cout << "Customer name: " << name << endl;
    cout << "Customer ID: " << newID << endl;
    cout << "Customer email: " << email << endl;
    cout << "Customer contact number: " << contactNumber << endl;
    cout << endl;
    cout << "------------------------------------" << endl;
}

// This block of code updates the information of an existing customer
void SystemManager::updateCustomerInfo(){
    string updateChoice;
    
    cout << "Type in customer ID you'd like to update: ";
    getline(cin, updateChoice);

    for(Customer& customer:customers){                         //Run through the list of customers
        if (updateChoice == customer.getCustomerID()){         //to check for matching results
            string name, email, contactNumber;
            
            cout << "Enter your new name: ";
            getline(cin, name);
            cout << "Enter your new email address: ";
            getline(cin, email);
            cout << "Enter your new contact number: ";
            getline(cin, contactNumber);

            customer.setName(name);
            customer.setEmail(email);
            customer.setContactNumber(contactNumber);

            saveData();

            system("cls");
            cout << "------------------------------------" << endl << endl;
            cout << customer.getCustomerID() << " Successfully updated" << endl << endl;
            cout << "Customer Name: " << customer.getName() << endl;
            cout << "Customer ID: " << customer.getCustomerID() << endl;
            cout << "Customer email: " << customer.getEmail() << endl;
            cout << "Customer contact number: " << customer.getContactNumber() << endl;
            cout << endl << "------------------------------------" << endl;
            return;
  
        }
    }
    system("cls");
    cout << "------------------------------------" << endl << endl;
    cout << "Customer not found." << endl << endl;
    cout << "------------------------------------" << endl << endl;
}

// This block of code calculates the discount applied when a customer avails a discount
double SystemManager::applyDiscount(double rentPerDay, int rentalDays){
    return (calculateBaseCost(rentPerDay, rentalDays)) * 0.10;  
}

// This block of code calculates the base cost of an instrument
double SystemManager::calculateBaseCost(double rentPerDay, int rentalDays){
    return(rentPerDay * rentalDays);
}

// This block of code calculates the overdue fee whenever the return date is past due
double SystemManager::applyOverdueFee(double rentPerDay, int rentalDays){
    return calculateBaseCost(rentPerDay, rentalDays) * 0.10;
}

// This block of code determines if the current date is greater than the assigned return date
bool SystemManager::isOverdue(const Rental &rental) {
    return getCurrentDate() > rental.getReturnDate();
}

// This block of code sets the return date
void SystemManager::setReturnDate(Rental& rental, int rentalDays){
    // Made by AI
    time_t now = time(nullptr);
    tm localTime{};
    localtime_s(&localTime, &now);

    string rentalDate = getCurrentDate();
    rental.setRentalDate(rentalDate);

    localTime.tm_mday += rentalDays;
    mktime(&localTime);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &localTime);
    rental.setReturnDate(buffer);
}

// This block of code displays the rental information, it is called on the displayAllRentals() function and is iterated to view the history of rentals
void SystemManager::displayRentalInfo(const Rental& rental){
    cout << "----------------------------------" << endl;
    cout << "Rental ID: " << rental.getRentalID() << endl;
    cout << "Rented Instrument ID: " << rental.getInstrumentID() << endl;
    cout << "Days to be rented: " << rental.getRentalDays() << endl;
    cout << "Rental Date: " << rental.getRentalDate() << endl;
    cout << "Return Date: " << rental.getReturnDate() << endl;
    cout << "Rented by: " << rental.getCustomerID() << endl;
    cout << "Total cost: " << rental.getTotalCost() << "PHP" << endl;
    cout << endl << "Status: ";
    if (rental.getIsCompleted()) {
        cout << "Completed" << endl;
    } else {
        cout << "Not yet returned" << endl;
    }
}

// This block of code searches instruments by brand
void SystemManager::searchInstrumentByBrand(){
    string brand;
    bool found = false;
    cout << "Enter brand to search: ";
    getline(cin, brand);
    for(char& c : brand) {
        c = toupper(c);
    }
    system("cls");
            cout << "------------------------------------" << endl << endl;
            cout << "\tResults for: " << brand << endl << endl;
    for (const Instrument& instrument : instruments)
    {
        if(instrument.getBrand() == brand)
        {
            found = true;
            cout << "----------------------------------" << endl;
            displayInstrument(instrument);
        }
    }
    if(!found)
    {
        
        cout << "\tNo instruments found." << endl << endl;
        
    }
    cout << "------------------------------------" << endl << endl;
}

// This block of code searches instruments by model
void SystemManager::searchInstrumentByModel(){
    string model;
    bool found = false;

    cout << "Enter model to search: ";
    getline(cin, model);

    system("cls");
            cout << "------------------------------------" << endl << endl;
            cout << "\tResults for: " << model << endl << endl;
    for(const Instrument& instrument : instruments)
    {
        if(instrument.getModel() == model)
        {
            found = true;
            cout << "----------------------------------" << endl;
            displayInstrument(instrument);
        }
    }

    if(!found)
    {
        cout << "\tNo instruments found." << endl << endl;
    }
    cout << "------------------------------------" << endl << endl;
}

// This block of code displays who rented a specific instrument
void SystemManager::displayWhoRentedWhat(){
    bool found = false;

    system("cls");
    cout << "------------------------------------" << endl;
    for(const Rental& rental : rentals)
    {
        if(!rental.getIsCompleted())
        {
            found = true;
            cout << "------------------------" << endl;
            cout << "Rental ID: " << rental.getRentalID() << endl;
            cout << "Customer ID: " << rental.getCustomerID() << endl;
            cout << "Instrument ID: " << rental.getInstrumentID() << endl;
            cout << "------------------------" << endl;
        }
    }

    if(!found)
    {
        cout << endl << "No active rentals found." << endl << endl;
    }
    cout << "------------------------------------" << endl;
}

// Sorts the list of instruments by order by rental price using the list's .sort() function.
void SystemManager::sortInstrumentsByPrice(){
    instruments.sort(
        [](const Instrument& a, const Instrument& b){           //LAMBDA FUNCTION TO SORT INSTRUMENTS BY PRICE - Joshua Comment
            return a.getRentPerDay() < b.getRentPerDay();
        }
    );

    cout << "Instruments sorted by price." << endl;
    displayAvailableInstruments();
}

// This block of code displays the menu
void SystemManager::displayMenu(){
    cout << endl << "-------- Musical Instrument Rental System --------" << endl << endl;
    cout << "\t [1]  - Add instrument" << endl;
    cout << "\t [2]  - Register Customer" << endl;
    cout << "\t [3]  - Rent Instrument" << endl;
    cout << "\t [4]  - Return Instrument" << endl;
    cout << "\t [5]  - View Available Instruments" << endl;
    cout << "\t [6]  - View Rental Records" << endl;
    cout << "\t [7]  - Update Customer Information" << endl;
    cout << "\t [8]  - Search Instrument By Brand" << endl;
    cout << "\t [9]  - Search Instrument By Model" << endl;
    cout << "\t [10] - View Who Rented What" << endl;
    cout << "\t [11] - Sort Instruments  By Price" << endl;
    cout << "\t [12] - View Waiting Queue" << endl;
    cout << "\t [13] - Exit" << endl;
    cout << endl << "--------------------------------------------------" << endl;
}


