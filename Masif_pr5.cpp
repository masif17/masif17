/* Class: CMSC140 CRN 30373
 Program: Project #5 Design
 Instructor: Rabiha Kayed
 Summary of Description: This program will make a magic square of numbers that their sum will be 15 from every side (top, bottom, diagonal) and numbers should must be between 1-9
 Due Date: 5/2/2024
 Integrity Pledge: I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 Print your Name here: Malaika Asif
*/




#include<iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows for the magic square
const int COLS = 3;  // The number of columns for the magic square
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkForRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkForUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkForRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkForColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkForDiagnalSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void InputForArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void FilledArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{
    /* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
    int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];

    // Fill the magic square with the numbers as input
    InputForArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    // Show the number in square enterd by the user
    FilledArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    // Check if the square is a magic square
    if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS))
    {
        cout << "This is a Lo Shu magic squaer" << endl;
    }
    else
    {
        cout << "This is not a magic square" << endl;
    }
    cout << " Thank You" << endl;
    cout << "PROGRAMMER: Malaika Asif" << endl;
    cout << "CMSC 140: Pr 5" << endl;
    cout << "Due date: 5/2/2024" << endl;



    return 0;
}





// Function definitions
void InputForArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    //fill the square with input from user
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter the number for row " << i << " and column " << j << " :";

            //using switch statement to test for different case
            switch (i)
            {
            case 0:
                cin >> arrayRow1[j];
                break;
            case 1:
                cin >> arrayRow2[j];
                break;
            case 2:
                cin >> arrayRow3[j];
                break;
            default:
                break;
            }
        }
    }
}





void FilledArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size = 3)
{
    for (int i = 0; i < size; i++)
    {
        cout << arrayRow1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arrayRow2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arrayRow3[i] << " ";
    }
    cout << endl;
}





bool checkForRowSum(int arrayrow1[], int arrayrow2
    [], int arrayrow3[], int size)
{
    // Calculate the sum of the numbers in each row
    int rowSum1 = 0, rowSum2 = 0, rowSum3 = 0;
    for (int i = 0; i < size; i++)
    {
        rowSum1 += arrayrow1[i];
        rowSum2 += arrayrow2[i];
        rowSum3 += arrayrow3[i];
    }
    // Check if all row sums are equal 
    if (rowSum1 == rowSum2 && rowSum2 == rowSum3)
    {
        return true;
    }
    else
    {
        return false;
    }
}




bool checkForRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
    //check if all values are in the range
    for (int i = 0; i < size; i++)
    {
        if (arrayRow1[i] < min || arrayRow1[i] > max ||
            arrayRow2[i] < min || arrayRow2[i] > max ||
            arrayRow3[i] < min || arrayRow3[i] > max)
        {
            return false;
        }
    }
    
    return true;
}




bool checkForUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arrayRow1[i] == arrayRow1[j] ||
                arrayRow2[i] == arrayRow2[j] ||
                arrayRow3[i] == arrayRow3[j])
            {
                return false;
            }
        }
    }
    return true;
}




bool checkForColSum(int arrayrow1[], int arrayRow2[], int arrayrow3[], int size)
{
    // Calculate the sum numbers in each columm
    int colSum1 = 0, colSum2 = 0, colSum3 = 0;
    for (int i = 0; i < size; i++)
    {
        colSum1 += arrayrow1[i];
        colSum2 += arrayRow2[i];
        colSum3 += arrayrow3[i];
    }
    // Check if all column sums are equal
    if (colSum1 == colSum2 && colSum2 == colSum3)
    {
        return true;
    }
    else
    {
        return false;
    }
}




bool checkForDiagnalSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    // Calculate the sum of numbers in each diagnal
    int diagnalSum1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
    int diagnalSum2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];

    // Check if both diagnol are equal
    if (diagnalSum1 == diagnalSum2)
    {
        return true;
    }
    else
    {
        return false;
    }
}




bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    // Check if all numbers are within range
    if (!checkForRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX))
    {
        return false;
    }
    // Check if all values are unique
    if (!checkForUnique(arrayRow1, arrayRow2, arrayRow3, size))
    {
        return false;
    }
    // Check if all row sums are equal
    if (!checkForRowSum(arrayRow1, arrayRow2, arrayRow3, size))
    {
        return false;
    }
    // Check if all column sums are equal
    if (!checkForColSum(arrayRow1, arrayRow2, arrayRow3, size))
    {
        return false;
    }
    // Check if both diagnals sums are equal
    if (!checkForDiagnalSum(arrayRow1, arrayRow2, arrayRow3, size))
    {
        return false;
    }
    return true;
 
}
