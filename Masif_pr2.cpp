/*
 * Class: CMSC140 CRN
 * Instructor: Rabiha Kayad
 * Project<2>
 * Description: (Give a brief description for Project)
 * In this project, the user will enter the movie from the list and the code will validate all 
 * the requirement and it will show error messeges for restrictions.
 * Due Date: 03/03/2024
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Malaika Noor Asif
*/

#include <iostream>
#include <string>
using namespace std;

int
main ()
{
  int Movie;
  int age;
  int TotalAdults;
  int TotalChild;
  int adult = 12;
  int child = 8;
  int total;
  int paying;
  int change;




  string m1 = "The Matrix - Rated R";
  string m2 = "Star Wars: Episode V - The Empire Strikes Back - Rated PG";
  string m3 = "Inception - Rated G";
  string m4 = "Toy Story - Rated G";
  string m5 = "Crash - Rated NC-17";

//defing all the movies




  cout << "******Movie Ticket Booking******" << endl;
  cout << "Let's see which movie would you like to see today?" << endl;
  cout << "Here is the list of movies that we have" << endl;
  cout << "1." << m1 << endl;
  cout << "2." << m2 << endl;
  cout << "3." << m3 << endl;
  cout << "4." << m4 << endl;
  cout << "5." << m5 << endl;

  cout << "Please select a movie by entering its number:" << endl;
  cin >> (Movie);


//below if statement will check if the mocie number entered is out of the range
//if yes it will display error message


  if (Movie > 5 || Movie < 1)
	{
	  cout << "Sorry, We don't have this movie" << endl;
	  return 1;

	  //return 1 means exit the program with an error code
	}

  cout << "Please enter your age:" << endl;
  cin >> age;


//below if statement will check if the user put negative age
  if (age < 0)
	{
	  cout << "Invalid age" << endl;
	  return 1;
	}


//we use switch statement to test differnt cases for the same integer
//which in this case is movie
  switch (Movie)
	{

	  //case 1,2,3 and so on will check for that specific line from the list
	case 1:
	  if (age < 17)
		{
		  cout << "Sorry, you must be 17 to watch " << "\"" << "The Matrix" <<
			"\"" << endl;
		  return 1;

		}
	  break;




//break is used to stop switch if the condition is true


	case 2:
	  if (age < 7)
		{
		  cout << "Sorry, you must be 7 to watch " << "\"" << "Star Wars" <<
			"\"" << endl;
		  return 1;

		}
	  break;


//break will be applied after every case


	case 3:
	  if (age < 13)
		{
		  cout << "Sorry, you must be 13 to watch " << "\"" << "Inception" <<
			"\"" << endl;
		  return 1;

		}
	  break;





	case 4:
	  {
		cout << "Enjoy, Toy Story" << endl;

	  }
	  break;



	case 5:
	  if (age < 18)
		{
		  cout << "Sorry, you must be 18 to watch " << "\"" << "Crash" << "\""
			<< endl;
		  return 1;

		}
	  break;



	default:
	  cout << "Ticket booth" << endl;
	}

//adult ticket price is $12
//child ticket price is $8

 
  cout <<"Age verification passed"<<endl;
  cout << "Let's buy tickets for you"<<endl;
  cout << "How many adult tickets would you like to buy?" << endl;
  cin >> TotalAdults;
  cout << "How many child tickets would you like to buy?" << endl;
  cin >> TotalChild;
  
  if (TotalAdults<0 || TotalChild<0)
  {
      cout<<"Invalid number of tickets"<<endl;
  }
  
  
  //this if statement will check and show error messege if the ticket for either adults or child is less than 0
  else
  {
      if (TotalChild > 0 && (Movie == 1) || (Movie == 5 ))
	    {
	    cout << "You can't buy child tickets for this movie." << endl;
	    return 1;
	    }

//child is any person below 13, m1 and m5, both are not for childern
//this if statement will and display error message if a person os trying to buy a child ticket that is restricted for that age

      else
	    {
	    total = (TotalAdults * adult) + (TotalChild * child);
	    
	    //to find total
	    //multiply the number of ticket for adult with the price of per ticket (12)
	    //multiply the number of ticket for chikd with the price of per ticket (8)
	    //add them both
	    cout << "Your total is: $" << total << endl;
	    cout << "Please enter the amount you are paying:" << endl;
	    cin >> paying;

	    if (paying < total)
	    	{
		     cout <<
		    	"Error: Amount paid is less than total cost. Transaction Cancelled"
		    	
		    	//this if statement will check and display error messege if the paid amount is less than the total amount
		    	<< endl;
		     return 1;
	    	}

        change = paying - total;
        cout << "Your change is $"<<change<< "."<<endl;
        
        //subtract the total amount with the paid amount to calculate change
	    cout << "Transaction approved! Enjoy your movie" << endl;

	}


  return 0;
}}
