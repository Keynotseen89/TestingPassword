// This program tests a password for the American Equities
// web page to see if the format is correct

// Author: Quinatzin Sintora.

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std; 

//function prototypes 

bool testPassWord(char[]);					//testPassWord true/false Function
int countLetters(char*);					//count letters in Function 
int countDigits(char*);						//count Digits in Functino

int main()
{
	int numbers, letters = 0;				//Set number and letters to Zero
	char passWord[20];						//Set char passWord array of a size of 20
	
	//Prompt user to Enter password 
	cout << "Enter a password consisting of exactly 5 "
		 << "letters and 3 digits:" << endl;
	
	//Using cin.getline to read input as character and digits
	cin.getline(passWord,20);

	//Check for validation of password
	if (testPassWord(passWord))
		cout << "Please wait - your password is being verified" << endl;
	else
	{
		cout << "Invalid password. Please enter a password "
		     << "with exactly 5 letters and 3 digits" << endl;
	    cout << "For example, my37RuN9 is valid" << endl;
	}

	letters = countLetters(passWord);			//Gets the number of letters
	numbers = countDigits(passWord);			//Gets the number of Digits
	cout << letters << endl;					//Prints the number of Letters in password
	cout << numbers << endl;					//Prints the number of Digits in password
	// FILL IN THE CODE THAT WILL CALL countLetters and 
	// countDigits and will print to the screen both the number of
	// letters and digits contained in the password.  

	return 0;									//return Zero at the end of main function
}


//**************************************************************
//                       testPassWord
//
// task:			determines if the word contained in the
//				    character array passed to it, contains
//					exactly 5 letters and 3 digits.
// data in:			a word contained in a character array
// data returned:   true if the word contains 5 letters & 3
//					digits, false otherwise
//
//**************************************************************
bool testPassWord(char custPass[])
{
	//variable used for numbers/digits/ and length
	int numLetters, numDigits, length;

	length = strlen(custPass);									//gets the length of password that was input
    numLetters = countLetters(custPass);						//gets the numbers of letters in password that was input
	numDigits = countDigits(custPass);							//gets the number of Digits in password that was input

	//Checks if all values are valid then
	//return true if not return false
	if (numLetters == 5 && numDigits == 3 && length == 8 )
		return true;
	else
		return false;
}


// the next 2 functions are from Sample Program 10.5
//**************************************************************
//                       countLetters
//
// task:			counts the number of letters (both
//                  capital and lower case in the string
// data in:			a string 
// data returned:   the number of letters in the string
//
//**************************************************************
int countLetters(char *strPtr) 
{
	int occurs = 0;					//Set occurs to zero

	//while stringPointer is not 
	//end value of '\0' in charactor 
	while(*strPtr != '\0')       
	{
		if (isalpha(*strPtr))  
			occurs++;
		strPtr++;
	}

	return occurs;					//returns number of letters
}

//**************************************************************
//                       countDigits
//
// task:			counts the number of digitts in the string
// data in:			a string 
// data returned:   the number of digits in the string
//
//**************************************************************
int countDigits(char *strPtr)  // this function counts the
                               // number of digits
{  
	int occurs = 0;				

	while(*strPtr != '\0')
	{
		if (isdigit(*strPtr))  // isdigit determines if
			                   // the character is a digit
			occurs++;
		strPtr++;
	}

	return occurs;				//returns the number of digits
}