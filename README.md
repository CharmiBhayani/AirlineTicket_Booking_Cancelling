# AirlineTicket_Booking_Cancelling
AIRLINE TICKET RESERVATION SYSTEM
(C++ Mini Project)

1. INTRODUCTION
The Airline Seat Reservation System is a console-based C++ application developed using object-oriented programming and file handling concepts.
This system allows users to view seat availability, book airline seats, and cancel booked seats.
All booking details are stored permanently using binary files.

2. OBJECTIVE OF THE PROJECT
•	To understand file handling in C++
•	To implement classes and objects
•	To manage real-world booking logic
•	To provide a simple menu-driven application

3. TECHNOLOGIES USED
•	Programming Language: C++
•	Concepts Used:
o	Classes & Objects
o	Binary File Handling (fstream)
o	String Handling (cstring)
o	Menu-driven Program
o	Console I/O

4. SYSTEM DESCRIPTION
The system simulates an airline flight with a fixed seat layout.
Each seat can have two states:
•	A → Available
•	B → Booked
Flight Details:
•	Airline: Air India
•	Flight Number: 5241
•	Date: 25/01/2026

5. SEAT LAYOUT DETAILS
•	Rows: A to J
•	Seats per Row: 1 to 7
•	Total Seats: 70
•	Passage is shown after specific rows for visualization

6. FILE STRUCTURE
File Name	Description
seat.dat	Stores seat number and seat status
user.dat	Stores customer booking details
new.dat	Temporary file used during cancellation

7. CLASS DESCRIPTION
7.1 Customer Class
Stores customer booking information:
•	Name
•	Seat Number
•	Phone Number
•	Booking Status
7.2 Seat Class
Stores seat information:
•	Seat Number
•	Seat Status (A / B)

8. FUNCTION DESCRIPTION
set_seat()
•	Initializes seat layout
•	Creates seat.dat if it does not exist
•	Marks all seats as Available initially
display()
•	Displays the seat layout
•	Shows seat number with availability status
•	Displays passage for clarity
book()
•	Books a selected seat
•	Stores customer details in user.dat
•	Updates seat status to Booked
cancel()
•	Cancels an existing booking
•	Updates seat status back to Available
•	Updates user records

9. MENU STRUCTURE
***** MENU *****
      1. Booking
      2. Canceling
      3. Exit

      Option 1: Booking
      •	Displays seat layout
      •	Takes seat number and customer details
      •	Confirms booking
      Option 2: Canceling
      •	Displays seat layout
      •	Cancels booking using seat number
      Option 3: Exit
      •	Terminates the program

10. HOW TO EXECUTE THE PROGRAM
Compilation
g++ main.cpp -o airline
Execution
./airline
Note:
This program works best on Windows OS due to usage of conio.h and system("cls").

11. CONCLUSION
This project successfully demonstrates the use of C++ file handling and OOP concepts to create a real-world airline seat reservation system.
It provides a strong foundation for understanding data persistence and menu-driven applications.

12. DECLARATION
This project is developed for educational purposes and has not been copied from any external source.

