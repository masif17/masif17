/*
 * Class: CMSC140 CRN
 * Instructor: Rabiha Kayed
 * Project<3>
 * Description: (Give a brief description for Project)
 * This program will calculate the entered the room with types, their cost, hotel Income, 
 * and the occupancy rate. This program will also tell which floor has minimum room in the hotel
 * Due Date: 3/27/2024
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Malaika
*/



#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


//constant integer for a fixed variable
const int SINGLE_ROOM_RATE = 60;
const int DOUBLE_ROOM_RATE = 75;
const int KING_ROOM_RATE = 100;
const int SUITE_ROOM_RATE = 150;
const int MAX_FLOORS = 5;
const int MAX_ROOMS_PER_FLOOR = 30;

int main()
{

    //1,2,3,4 assigned to different rooms
    string room1 = "single Room";
    string room2 = "Double Room";
    string room3 = "King Room";
    string room4 = "Suite Room";

    //using string for location
    string location;

    //numberofFloors is the total number of floors in a hotel
    int numberOfFloors;

    //roomsOnFloor is the total rooms on that floor
    int roomsOnFloor;

    //occSingle means occupied Single Room, and so on for other rooms
    int occSingle, occDouble, occKing, occSuite;
    int RoomPrice1, RoomPrice2, RoomPrice3, RoomPrice4;
    int totalRooms = 0;
    int totalOccupied = 0;
    int unOccupied = 0;
    int HotelIncome = 0;
    int currentFloor = 1;
    double occupancyRate;

    //minRooms will be the monimum rooms amoung all the floors
    //MAX_ROOMS_PER_FLOOR + 1 indicates that the minimum number of rooms a floor can have
    //is max rooms per floor added one
    int minRooms = MAX_ROOMS_PER_FLOOR + 1;

    //initializing minimum floor 
    int minFloor = 0;


    cout << "Welcome to BlueMont Hotel" << endl;
    cout << "___________________________" << endl;
    cout << "___________________________" << endl;
    cout << "Please enter the location of this hotel chain" << endl;
    cin >> location;
    cout << "Enter the number of floors in the hotel:" << endl;
    cin >> numberOfFloors;


    //this while loop will test for if the user has entered floors less than 1 or greater than 5
    //if the input is invalid, it will show error messege and start the loop again

    while (numberOfFloors < 1 || numberOfFloors > MAX_FLOORS) {
        cout << "Error, Invalid floors. The Floors should be between 1 and 5:" << endl;
        cout << "Enter the number of floors in the hotel:" << endl;
        cin >> numberOfFloors;
    }

    while (currentFloor <= numberOfFloors)

    {

        cout << "Enter the total number of rooms on floor " << currentFloor << endl;
        cin >> roomsOnFloor;


        //this while loop will test if the user has entered less than 1 or more than 30 room for one floor
        while (roomsOnFloor < 1 || roomsOnFloor > MAX_ROOMS_PER_FLOOR) {
            cout << "Invalid Rooms, Please enter rooms between 1 and 30, Try Again" << endl;
            cout << "Enter the total number of rooms on floor " << currentFloor << endl;
            cin >> roomsOnFloor;
        }

        //totalRooms = totalRooms + roomsOnFloor
        totalRooms += roomsOnFloor;

        cout << "Here are the rooms that we have:" << endl;
        cout << room1 << endl;
        cout << room2 << endl;
        cout << room3 << endl;
        cout << room4 << endl;

        cout << "Enter the type of rooms occupied:" << endl;
        cout << "Occupied Single Rooms:" << endl;
        cin >> occSingle;
        cout << "Occupied Double Rooms:" << endl;
        cin >> occDouble;
        cout << "Occupied King Rooms:" << endl;
        cin >> occKing;
        cout << "Occupied Suite Rooms:" << endl;
        cin >> occSuite;


        //if the sum of all the room occupied is greater than 30, it will show error that invalid rooms entered
        //after error, this loop will ask user to enter the occupied rooms again
        while ((occSingle + occDouble + occKing + occSuite) > 30) {
            cout << "Invalid rooms entered" << endl;

            cout << "Enter the type of rooms occupied:" << endl;
            cout << "Occupied Single Rooms:" << endl;
            cin >> occSingle;
            cout << "Occupied Double Rooms:" << endl;
            cin >> occDouble;
            cout << "Occupied King Rooms:" << endl;
            cin >> occKing;
            cout << "Occupied Suite Rooms:" << endl;
            cin >> occSuite;

        }


        //this if statement block will check for all the rooms on every floor
        //then it will display the floor with the minimum rooms
        if (roomsOnFloor < minRooms) {
            minRooms = roomsOnFloor;
            minFloor = currentFloor;
        }
        
        //this increment will allow the code to keep looping and ask for rooms on floors
        //until the entered floor number is reached
        currentFloor++;

        }


    //below calculations will calculate the price for every room type based on per night price
    RoomPrice1 = SINGLE_ROOM_RATE * occSingle;
    RoomPrice2 = DOUBLE_ROOM_RATE * occDouble;
    RoomPrice3 = KING_ROOM_RATE * occKing;
    RoomPrice4 = SUITE_ROOM_RATE * occSuite;

    HotelIncome = RoomPrice1 + RoomPrice2 + RoomPrice3 + RoomPrice4;

    totalOccupied = occSingle + occDouble + occKing + occSuite;
    unOccupied = totalRooms - totalOccupied;
    occupancyRate = (static_cast<double>(totalOccupied) / totalRooms) * 100;

   

    cout << "Blue Mont Hotel in " << location << endl;

   
    cout << "Hotel Income is: "  << "$" << HotelIncome << endl;
    cout << "Occupied Rooms are: " << totalOccupied << endl;
    cout << "Unoccupied Rooms are:" << unOccupied << endl;

    //setprecision is used to show output with specific number of decimal points
    cout << fixed << setprecision(2);
    cout << "Occupancy Rate is: " << occupancyRate << "%" << endl;

    if (occupancyRate < 60) {
        cout << "Improvement is need. Your Occupancy Rate is lower than 60%" << endl;
    }

    cout << "Floor with minimum number of rooms is: " << minFloor << " with minimum rooms " << minRooms << endl;

    cout << "Thank you for testing my program" << endl;
    cout << "PROGRAMMER: Malaika" << endl;
    cout << "CMSC 140: Project 3" << endl;
    cout << "Due Date: 3/27/2024" << endl;

    return 0;
}

