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

// --------------------------- RENTAL ----------------------------
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
    saveQueuedata();
}

void SystemManager::saveQueuedata(){
    ofstream myQueueData("QueueData.txt");
    if(myQueueData.is_open()){
        for(const auto& request:waitingQueue){
            myQueueData << request.queueID << "|" << request.customerID << "|" << request.customerName << "|" << request.instrumentID << "|" << request.instrumentName << "|" << request.requestDate << endl;
        }
    }
    myQueueData.close();
}

void SystemManager::loadData(){
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

    cout << "NUMBER OF INSTRUMENTS: " << instruments.size() << endl;
    cout << "NUMBER OF CUSTOMERS: " << customers.size() << endl;
    cout << "NUMBER OF RENTALS: " << rentals.size() << endl;
    
    loadQueuedata();
}

void SystemManager::loadQueuedata(){
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
        cout << "No data in the Queue..." << endl;
        cout << "Starting with an empty queue." << endl;
    }
    myQueueData.close();
}

void SystemManager::enqueueWaitingCustomer(const string& customerID, const string& customerName, const string& instrumentID, const string& instrumentName){
    WaitingRequest request;
    request.queueID = generateID(WAITING_PREFIX);
    request.customerID = customerID;
    request.customerName = customerName;
    request.instrumentID = instrumentID;
    request.instrumentName = instrumentName;
    request.requestDate = getCurrentDate();

    waitingQueue.push_back(request);

    cout << "Instrument is currently rented." << endl;
    cout << "Customer " << customerID << " has been added to the waiting queue." << endl;
    cout << "Queue ID: " << request.queueID << endl;
}

void SystemManager::displayWaitingQueue(){
    bool found = false;
    cout << "===WAITING QUEUE===\n";
    for(const auto& request:waitingQueue){
        found = true;
        cout << "Queue ID: " << request.queueID << endl;
        cout << "Customer ID: " << request.customerID << endl;
        cout << "Customer Name: " << request.customerName << endl;
        cout << "Instrument ID: " << request.instrumentID << endl;
        cout << "Instrument Name: " << request.instrumentName << endl;
        cout << "Request Date: " << request.requestDate << endl;
        cout << "========================================" << endl;
    } 
    if(!found){
        cout << "The waiting queue is empty..." << endl;
    }
}

void SystemManager::processWaitingQueueForInstrument(const string& instrumentID){
    for(auto it = waitingQueue.begin(); it != waitingQueue.end(); it++){
        if(it->instrumentID == instrumentID){
            cout << "Next customer for this instrument:" << endl;
            cout << "Customer ID: " << it->customerID << endl;
            cout << "Customer Name: " << it->customerName << endl;
            cout << "The customer has now been served, removing from queue..." << endl;

            waitingQueue.erase(it);
            return;
        }
    }
}
void SystemManager::displayAvailableInstruments(){
    bool found = false;
    int displayNumber = 1;
    for (const auto& instrument : instruments){
        if (instrument.getIsAvailable()){
            found = true;
            cout << "---------------------------------" << endl;
            cout << "INSTRUMENT NO. " << displayNumber << endl;
            displayInstrument(instrument);
            displayNumber++;
        }
    }
    cout << "-----------------------" << endl;
    if(!found){
        cout << "No available instrument found." << endl;
    }
}

void SystemManager::displayAllInstruments(){
    int displayNumber = 1;
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
}

void SystemManager::displayInstrument(const Instrument& instruments){ 
    cout << "Instrument ID: " << instruments.getInstrumentID() << endl;
    cout << "Name: " << instruments.getName() << endl;
    cout << "Brand: " << instruments.getBrand() << endl;
    cout << "Model: " << instruments.getModel() << endl;
    cout << "Rent per day: " << instruments.getRentPerDay() << endl;
    cout << endl;
}

void SystemManager::displayAllRentals(){
    for (const Rental& rental : rentals){
        cout << "-----------------------" << endl;
        displayRentalInfo(rental);
    }
}

void SystemManager::rentInstrument(){
    int userChoice, rentalDays;
    bool isCompleted = false;
    string customerID;

    // TODO: check if customer has a valid ID, then proceed to rent
    cout << "Enter customer ID: ";
    cin >> customerID;

    bool customerFound = false;

    for (const Customer& customer : customers){
        if (customer.getCustomerID() == customerID ){
            customerFound = true;
            break;
        }
    }

    if (!customerFound)
    {
        cout << "Customer ID not found." << endl;
        return;
    }

    displayAllInstruments();
    cout << "Select the Instrument Number you'd like to rent:"; // Please change this
    cin >> userChoice;

    if (userChoice <= 0){
        cout << "Input a valid number." << endl;
        return;
    }

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
        cout << "Input a valid number." << endl;
        return;
    }

    //If the instrument is unavailable, ask the customer if they want to join the queue.
    if(!it->getIsAvailable()){
        bool answer = false;
        cout << "This instrument is currently rented.\n";
        cout << "Would you like to join the waiting queue? (1 for yes, 0 for no): ";
        cin >> answer;

        if(answer){
            string customerName;
            
            for(const Customer& customer:customers){
                if(customer.getCustomerID() == customerID){
                    customerName = customer.getName();
                    break;
                }
            }

            enqueueWaitingCustomer(customerID, customerName, it->getInstrumentID(), it->getName());
            saveQueuedata();
        }
        return;
    }

    cout << "Selected: " << it->getName() << endl;
    cout << "How many days would you like to rent this instrument? ";
    cin >> rentalDays;

    if (rentalDays <= 0){
        cout << "Rental days must be greater than 0." << endl;
        return;
    }

    bool discountApplied = false;
    cout << "Apply 10% discount? (1 for yes, 0 for no): ";
    cin >> discountApplied;

    it->setIsAvailable(false);

    string newID = generateID(RENTAL_PREFIX);
    double baseCost = calculateBaseCost(it->getRentPerDay(), rentalDays);
    double discountAmmount = applyDiscount(it->getRentPerDay(), rentalDays);
    double totalCost = discountApplied ? baseCost - discountAmmount : baseCost;

    Rental newRental(rentalDays, totalCost, false, it->getInstrumentID(), newID, customerID, "", "");
    setReturnDate(newRental, rentalDays);
    rentals.push_back(newRental);
    cout << "Rented instrument with the ID of " << newID << endl;    
    saveData();
}

void SystemManager::returnInstrument(){
    string choice;
    cout << "Type the rental ID you'd like to return: ";
    cin >> choice;

    // cant use range based for loops cause i need to use rental.erase to clear memory fuckkkkkkkkk
    for (auto i = rentals.begin(); i != rentals.end(); i++){
        if (choice == i->getRentalID()){
            string instrumentId = i->getInstrumentID();
            double rentPerDay = 0;
            
            for (Instrument& instrument : instruments){
                if(instrument.getInstrumentID() == instrumentId){
                    instrument.setIsAvailable(true);
                    rentPerDay = instrument.getRentPerDay();
                    break;
                }
            }

            cout << i->getInstrumentID() << " returned!" << endl;

            double totalCost = i->getTotalCost();
            if(isOverdue(*i)){
                double overDueFee = applyOverdueFee(rentPerDay, i->getRentalDays());
                double finalCost = totalCost + overDueFee;
                cout << "Rental cost: " << totalCost << "PHP" << endl;
                cout << "Overdue fee: " << overDueFee << "PHP" << endl;
                cout << "Total to pay: " << finalCost << "PHP" << endl;
            }else{
                cout << "Please pay " << totalCost << "PHP at the counter." << endl;
            }

            i->setIsCompleted(true);
            processWaitingQueueForInstrument(instrumentId);
            saveData();
            return;
        }
    }
    cout << "Rental ID not found." << endl;
}

void SystemManager::addInstrument(){
    string name, brand, model;
    double rentPerDay;
    bool isAvailable = true;

    cout << "----------------------------" << endl;
    cout << "Enter instrument name: ";
    getline(cin, name);
    cout << "Enter instrument brand: ";
    getline(cin, brand);
    cout << "Enter Instrument model: ";
    getline(cin, model);
    cout << "Enter rent per day (PHP): ";
    cin >> rentPerDay;

    string newID = generateID(INSTRUMENT_PREFIX);

    Instrument newInstrument(name, brand, model, newID, rentPerDay, isAvailable);
    instruments.push_back(newInstrument);
    cout << endl;
    cout << "Instrument added with the ID of '" << newID << "'" << endl;
    cout << "----------------------------" << endl;
}

string SystemManager::generateID(string prefix){
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
    }else if(prefix == WAITING_PREFIX){
        waitingCounter++;
        id += to_string(waitingCounter);
    }
    return id;
}

string SystemManager::getCurrentDate(){
    // imma be fr this is AI
    time_t now = time(nullptr);
    tm localTime{};

    localtime_s(&localTime, &now);  // Windows version

    stringstream ss;
    ss << put_time(&localTime, "%Y-%m-%d");
    return ss.str();
}

void SystemManager::addCustomer(){
    string name, customerID, email, contactNumber;  

    cout << "------------------------------" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your email address: ";
    cin >> email;
    cout << "Enter your contact number: ";
    cin >> contactNumber;

    string newID = generateID(CUSTOMER_PREFIX);
    Customer newCustomer(name, newID, email, contactNumber);
    customers.push_back(newCustomer);

    cout << endl << "Added customer with the ID of '" << newID << "'" << endl;
    cout << "----------------------------" << endl;
}

void SystemManager::updateCustomerInfo(){
    string updateChoice;
    
    cout << "Type in customer ID you'd like to update: ";
    cin >> updateChoice;

    for(Customer& customer:customers){
        if (updateChoice == customer.getCustomerID()){
            string name, email, contactNumber;
            
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your email address: ";
            cin >> email;
            cout << "Enter your contact number: ";
            cin >> contactNumber;

            customer.setName(name);
            customer.setEmail(email);
            customer.setContactNumber(contactNumber);

            cout << "Customer Updated." << endl;
            return;
        }
    }
    cout << "Customer not found." << endl;
}

double SystemManager::applyDiscount(double rentPerDay, int rentalDays){
    double baseCost = calculateBaseCost(rentPerDay, rentalDays);
    return baseCost * 0.10; // 10% discounts
}

double SystemManager::calculateBaseCost(double rentPerDay, int rentalDays){
    return(rentPerDay * rentalDays);
}

double SystemManager::applyOverdueFee(double rentPerDay, int rentalDays){
    double baseCost = calculateBaseCost(rentPerDay, rentalDays);
    return baseCost * 0.10;
}

bool SystemManager::isOverdue(const Rental &rental) {
    return getCurrentDate() > rental.getReturnDate();
}

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

void SystemManager::displayRentalInfo(const Rental& rental){
    cout << "----------------------------------" << endl;
    cout << "Rental ID: " << rental.getRentalID() << endl;
    cout << "Rented Instrument ID: " << rental.getInstrumentID() << endl;
    cout << "Days to be rented: " << rental.getRentalDays() << endl;
    cout << "Rental Date: " << rental.getRentalDate() << endl;
    cout << "Return Date: " << rental.getReturnDate() << endl;
    cout << "Rented by: " << rental.getCustomerID() << endl;
    cout << "Total cost: " << rental.getTotalCost() << "PHP" << endl;
    cout << "Completed: " << (rental.getIsCompleted() ? "true" : "false") << endl;
}

void SystemManager::searchInstrumentByBrand(){
    string brand;
    bool found = false;
    cout << "Enter brand to search: ";
    cin >> brand;
    for (const Instrument& instrument : instruments)
    {
        if(instrument.getBrand() == brand)
        {
            found = true;
            displayInstrument(instrument);
        }
    }
    if(!found)
    {
        cout << "No instrument found." << endl;
    }
}
void SystemManager::searchInstrumentByModel(){
    string model;
    bool found = false;

    cout << "Enter model to search: ";
    cin >> model;

    for(const Instrument& instrument : instruments)
    {
        if(instrument.getModel() == model)
        {
            found = true;
            displayInstrument(instrument);
        }
    }

    if(!found)
    {
        cout << "No instrument found." << endl;
    }
}
void SystemManager::displayWhoRentedWhat(){
    bool found = false;

    for(const Rental& rental : rentals)
    {
        if(!rental.getIsCompleted())
        {
            found = true;

            cout << "Rental ID: " << rental.getRentalID() << endl;
            cout << "Customer ID: " << rental.getCustomerID() << endl;
            cout << "Instrument ID: " << rental.getInstrumentID() << endl;
            cout << "------------------------" << endl;
        }
    }

    if(!found)
    {
        cout << "No active rentals found." << endl;
    }
}
void SystemManager::sortInstrumentsByPrice(){
    instruments.sort(
        [](const Instrument& a, const Instrument& b){
            return a.getRentPerDay() < b.getRentPerDay();
        }
    );

    cout << "Instruments sorted by price." << endl;
    displayAvailableInstruments();
}

void SystemManager::displayMenu(){
    cout << "-------- Musical Instrument Rental System --------" << endl;
    cout << "1. Add instrument" << endl;
    cout << "2. Register Customer" << endl;
    cout << "3. Rent Instrument" << endl;
    cout << "4. Return Instrument" << endl;
    cout << "5. View Available Instruments" << endl;
    cout << "6. View Rental Records" << endl;
    cout << "7. Update Customer Information" << endl;
    cout << "8. Search Instrument By Brand" << endl;
    cout << "9. Search Instrument By Model" << endl;
    cout << "10. View Who Rented What" << endl;
    cout << "11. Sort Instruments  By Price" << endl;
    cout << "12. View Waiting Queue" << endl;
    cout << "13. Exit" << endl;
}