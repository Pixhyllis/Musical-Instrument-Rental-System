#include "CoreClasses.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    SystemManager system;
    int choice;

    cout << "________________________________________________________________________" << endl << endl;
    cout << "\tCCS0015L - Data Structures and Algorithms (LAB)" << endl;
    cout << "\t Final Project: Musical Instrument Rental System" << endl;
    cout << "\t Members:  Balleta, Chang, Salanguit, Vales" << endl;
    cout << "________________________________________________________________________" << endl;    
    system.loadData();
    do{
        system.displayMenu();
        cout << endl << "Type in your choice: ";
        cin >> choice;
        cin.ignore();
         switch (choice)
            {
            case 1:
                system.addInstrument();   // displays add instrument menu and calls the addInstrument function
                break;
            case 2:
                system.addCustomer();    // displays add customer menu and calls the addCustomer function
                break;
            case 3:
                system.rentInstrument(); // displays rent instrument menu and calls the rentInstrument function
                break;
            case 4:
                system.returnInstrument(); // displays return instrument menu and calls the returnInstrument function
                break;
            case 5:
                system.displayAvailableInstruments(); // displays available instruments menu and calls the displayAvailableInstruments function
                break;
            case 6:
                system.displayAllRentals(); // displays all rentals menu and calls the displayAllRentals function
                break;
            case 7:
                system.updateCustomerInfo(); // displays update customer info menu and calls the updateCustomerInfo function
                break;
            case 8:
                system.searchInstrumentByBrand(); // displays search instrument by brand menu and calls the searchInstrumentByBrand function
                break;
            case 9:
                system.searchInstrumentByModel();// displays search instrument by model menu and calls the searchInstrumentByModel function
                break;
            case 10:
                system.displayWhoRentedWhat(); // displays who rented what menu and calls the displayWhoRentedWhat function
                break;
            case 11:
                system.sortInstrumentsByPrice(); // displays sort instruments by price menu and calls the sortInstrumentsByPrice function
                break;
            case 12:
                system.displayWaitingQueue(); // displays waiting queue menu and calls the displayWaitingQueue function
                break;
            case 13:
                system.saveData();
                cout << "Bye Bye!" << endl; // displays exit menu and calls the saveData function
                break;
            default:
                cin.clear();
                cin.ignore(1000, '\n');
                ::system("cls");
                cout << "------------------------------------" << endl << endl;
                cout << "Invalid choice. Please try again." << endl << endl;
                cout << "------------------------------------" << endl << endl;
                break;
            }
    } while (choice != 13);
    return 0;
}



