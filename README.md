# Musical-Instrument-Rental-System
For data struct finals

This is intended to be seen by my groupmates.
For my group mates, please say here:

RB - HERE

AC - HERE

JV - HERE

JL - HERE

BASIC SYSTEM / CORE CLASSES
- A class about the instrument and it's details (model, name, etc)
- A class about customer details (use linked list or sum)
- A class about rental shit like what instrument has been rented, who rented it, the cost of renting, how long its been rented
- A class to manage what's above ^^^

FEATURES TO ADD
- [ ] File handling
- [x] Unique ID generation for renting
- [ ] Search & Filter (brand/model, available instruments, who's renting what instrument)
- [ ] Sorting (instrument rent price, rental date, customers' names)
- [ ] Report (daily income, list of currently rented instruments, rental history)
- [ ] Exception handling (if instrument unavailable type shit)
- [ ] Data validation (make sure that the customer exists before renting, and prevent renting an invalid amount of time; renting days <0)
- [ ] Queue Rental Waiting list (PRIORITY, if a customer wants to rent an unavailable instrument, put them in a waiting list)


OPTIONAL THINGS TO ADD:
- [ ] add a subclass for instruments(some has discounts and others are expensive depending on the brand)
- [ ] random discounts system
- [ ] loyalty points
- [x] track rental dates & calculate overdue fees
- [ ] Customer and Admin menu
- [ ] Currency system to pay for rental fees type shit

Pseudocode for the system MADE BY AI:

1. Start program
2. Create lists for instruments, customers, and rentals
3. Show menu:
   1. Add instrument
   2. Register customer
   3. Rent instrument
   4. Return instrument
   5. View available instruments
   6. View rental records
   7. Exit
4. If user chooses add instrument:
   1. Ask for instrument name, brand, model, rental price per day
   2. Generate instrument ID
   3. Set available to true
   4. Save instrument in instrument list
5. If user chooses register customer:
   1. Ask for customer name, email, contact number
   2. Generate customer ID
   3. Save customer in customer list
6. If user chooses rent instrument:
   1. Ask for customer ID and instrument ID
   2. Find customer and instrument
   3. Check if instrument is available
   4. If available, ask for number of rental days
   5. Calculate total cost = rental days × rental per day
   6. Create rental record
   7. Mark instrument as not available
   8. Save rental record
7. If user chooses return instrument:
   1. Ask for rental ID or instrument ID
   2. Find matching rental
   3. Mark instrument as available
   4. Mark rental as completed
8. If user chooses view available instruments:
   1. Loop through instrument list
   2. Display only instruments marked available
9. If user chooses view rental records:
   1. Loop through rental list
   2. Display all rental details
10. Repeat menu until user exits
11. End program
