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
        for(int i = 0; i < instruments.size(); i++){
            myInsData << instruments[i].getName() << "|"
                   << instruments[i].getBrand() << "|"
                   << instruments[i].getModel() << "|"
                   << instruments[i].getInstrumentID() << "|"
                   << instruments[i].getRentPerDay() << "|"
                   << instruments[i].getIsAvailable() << endl;
        };
    }
    myInsData.close();

    ofstream myCustData("CustData.txt");
    if (myCustData.is_open()){ 
        for(int i = 0; i < customers.size(); i++){
            myCustData << customers[i].getName() << "|"
                   <<  customers[i].getCustomerID()<< "|"
                   << customers[i].getEmail() << "|"
                   << customers[i].getContactNumber() << endl;
        };
    }
    myCustData.close();
    
    ofstream myRentData("RentData.txt");
    if(myRentData.is_open()){
        for (int i = 0; i < rentals.size(); i++){
            myRentData << rentals[i].getRentalDays() << "|" 
                       << rentals[i].getTotalCost() << "|"
                       << rentals[i].getIsCompleted() << "|"
                       << rentals[i].getInstrumentID() << "|"
                       << rentals[i].getRentalID() << "|"
                       << rentals[i].getCustomerID() << "|"
                       << rentals[i].getRentalDate() << "|"
                       << rentals[i].getReturnDate() << endl;
        }
    }

    myRentData.close();
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

}

void SystemManager::displayAvailableInstruments(){
    bool found = false;
    for (int i = 0; i < instruments.size(); i++){
        if (instruments[i].getIsAvailable()){
            found = true;
            cout << "---------------------------------" << endl;
            cout << "INSTRUMENT NO. " << i + 1 << endl;
            displayInstrument(instruments[i]);
        }
    }
    if(!found){
        cout << "No available instrument found." << endl;
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
    for (const Customer& customer : customers)
    {
        if (customer.getCustomerID() == customerID )
        {
            customerFound = true;
            break;
        }
    }
    if (!customerFound)
    {
        cout << "Customer ID not found." << endl;
        return;
    }
    displayAvailableInstruments();
    cout << "Select what Instrument you'd like to rent:"; // Please change this
    
    cin >> userChoice;
    int selectedIndex = userChoice - 1;

    if(selectedIndex >= 0 && selectedIndex < instruments.size()){
        Instrument selectedInstrument = instruments[selectedIndex];
        
        cout << "Selected: " << selectedInstrument.getName() << endl;
        cout << "How many days would you like to rent this instrument? ";
        cin >> rentalDays;
        // To confirm or Validate yung days ng rental
        if(rentalDays <= 0)
        {
            cout << "Rental days must be greater than 0." << endl;
            return;
        }
        bool discountApply = false;
        cout << "Apply 10% discount? (1 for yes, 0 for no): ";
        cin >> discountApply;

        instruments[selectedIndex].setIsAvailable(false);
        
        string newID = generateID(RENTAL_PREFIX);
        double baseCost = calculateBaseCost(selectedInstrument.getRentPerDay(), rentalDays);
        double discountAmount = applyDiscount(selectedInstrument.getRentPerDay(), rentalDays);
        double totalCost;

        if (discountApply) {
            totalCost = baseCost - discountAmount;
        } else {
            totalCost = baseCost;
        }
    
        Rental newRental(rentalDays, totalCost, isCompleted ,selectedInstrument.getInstrumentID(), newID, customerID, "", "");
        
        setReturnDate(newRental, rentalDays);
        rentals.push_back(newRental);

        cout << "Rented instrument with the ID of " << newID << endl;
    
    }else{
        cout << "Input a valid number." << endl;
    }
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

    cout << "Instrument added with the ID of '" << newID << "'" << endl;
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

    cout << "Added customer with the ID of '" << newID << "'" << endl;
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

void SystemManager::sortInstrumentsByPrice(){
    sort(
        instruments.begin(),
        instruments.end(),
        [](const Instrument& a, const Instrument& b)
        {
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
    cout << "9. Sort Instruments  By Price" << endl;
    cout << "10. Exit" << endl;
}