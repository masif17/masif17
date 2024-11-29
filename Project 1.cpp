/*
 * Class: CMSC140 CRN
 * Instructor:
 * Project<number>
 * Description: (Give a brief description for Project)
 * Due Date:
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Malaika
*/






#include <iostream>
using namespace std;

int main() 
{
    cout << "Welcome to the programming event!" << endl;

    cout << "Enter your name: ";
    string name;
    cin >> name;

    //name, that the user will input

    cout << "Hello, " << name << "!" << endl;

    cout << "What is your favorite number?" << endl;
    double number;

    //we will be using the double data type so that our code can work 
    // even if the answer is in decimals

    cin >> number;

    // Calculate twice the number

    double twice = number + number; 
    cout << "Double of " << number << " is " << twice << endl;

    //Calculate the half of the number

    double half = number / 2;
    cout << "Half of " << number << " is " << half << endl;

    // Calculate the square of the number

    double square = number * number; 
    cout << "Square of " << number << " is " << square << endl;

    // Calculate the square root of the number

    double root = sqrt(number); 
    cout << "Square root of " << number << " is approximately " << root << endl;

    cout << "Now," << name << " let's explore division. Give me the whole number." << endl;
    int num1;
    int num2;

    //int number data type means that the numbers enterd are integers

    cin >> num1;

    //num1 is the first number entered by the user

    cout << "Now, give me another whole numer." << endl;
    cin >> num2;

    //num2 is the second number entered by the user

    int division;

    //integral division is to divide integer with an integer

    division = num1/num2;
        cout << "Using integer division," << num1 << " divided by " << num2 << " is " << division << endl;

    float point;

    //float point diviosn is to get the answer if it is in decimals

    point = num1/num2;
        cout << "Using float point division," << num1 << " divided by " << num2 << " is approximately " << point << endl;

        cout << "Thank you for participating " << name << endl;
        cout << "PROGRAMMER: Malaika" << endl;
        cout << "CMSC 140 Project1" << endl;
        cout << "CMSC 140 Project1" << endl;
        cout << "Due Date: 2/14/2024" << endl;
        
        //we use system pause to remove the junk stuff on the bottom of screen after the program runs

        system("pause");

    return 0;
}
