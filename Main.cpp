/*Programmer: Jason Carruthers
/Comp 235: Advanced Programming in C++
/Instructor: Dave Harden
/Date: 1/31/12
/Name of Project: Fractions
/This program uses a class Fraction to perform different operations between
/	two different fractions or one fraction and one integer. Functions don't duplicate,
/	so the idea is to create a versatile but efficient Fraction class.
/No user input is required, other than when there's a system("pause")
/Any output will be documented where it occurs in this program
*/


#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <ctime>
#include "Classes.h"
using namespace std;

//--------------------------------------------------------------------------
//Function prototypes
//--------------------------------------------------------------------------
void DrawDashMarks(int numLines = 1);
void MakeNewLine(int numCarriageReturns = 0);
void ReadFractionsFromFile();
bool IsNotEndOfFile(ifstream& in);
void TestFractionObjectInstantiation();
void TestArithmeticOperators();
void TestRelationalOperators();
void TestShorthandArithmeticAssignmentOperators();
void TestReduce();

//--------------------------------------------------------------------------
//Functions
//--------------------------------------------------------------------------
//This function sequentially calls different functions that utilize the Fraction class.
//When this function returns, the program ends.
int main()
{
	srand(static_cast<int>(time(0)));

	//TestFractionObjectInstantiation();

	//TestReduce();
	//ReadFractionsFromFile();

	//TestArithmeticOperators();
	//TestRelationalOperators();
	TestShorthandArithmeticAssignmentOperators(); //BUG: SHORTHAND ARITHMETIC OPS

	system("pause");
	return 0;
}




//This function draws the '-' character 80 times on one line, then prints a carriage return.
//"numLines" is how many lines of dash marks the user wants displayed to the screen adjacent to each other.
//This function is just for polish and to make the output more readable.
void DrawDashMarks(int numLines)
{
	const int SCREEN_WIDTH = 80;
	numLines = (numLines < 1) ? 1 : numLines;

	for(int i = 0; i < numLines; i++)
	{
		for(int i = 0; i < SCREEN_WIDTH; i++)
			cout << "-";
		cout << "\n";
	}
}




//This function calls the "DrawDashMarks" function. It draws one line of dash marks, then draws numCarriageReturns of
//extra carriage returns. Since DrawDashMarks already prints one carriage return after each line of dash marks, this
//function's default value for numCarriageReturns is zero, because that would still leave the cursor on a new line.
void MakeNewLine(int numCarriageReturns)
{
	numCarriageReturns = (numCarriageReturns < 0) ? 0 : numCarriageReturns;

	cout << "\n";
	DrawDashMarks(1);

	for(int i = 0; i < numCarriageReturns - 1; i++)
		cout << "\n";
}




//This function reads fractions from a file (in this case a text file), then outputs each fraction after it's read.
//Though this is "client code" and not supposed to be touched, I changed some of the formatting and changed the output
//to read "Reduced form of read Fractions" because after each fraction is read it's reduced to its smallest form immediately.
//If I didn't fear getting a zero on this project, I would make this function more versatile by taking a string fileName as
//a parameter and creating an ifstream object with that data.
void ReadFractionsFromFile()
{
	ifstream in("FractionData.txt");
	assert(in);

	cout << "Fractions read from a text file:";
	MakeNewLine(4);

	while( !IsNotEndOfFile(in) )
	{
		Fraction fraction;

		if(in.peek() == '#')
			in.ignore(10000, '\n'); //skip this line, it's a comment
		else
		{
			in >> fraction;

			cout << "Reduced form of read Fraction:\t\t" << fraction;
			MakeNewLine();
		}
	}

	system("pause");
	system("cls");
};




//This function is utilized in the "ReadFractionsFromFile" function (originally called eof).
//It checks the next character in the file in (parameter), and if that character is past the end of the file then it's
//put into an error state; the function will return false. Otherwise, the function will return true.
bool IsNotEndOfFile(ifstream& in)
{
	char ch;
	in >> ch;
	in.putback(ch);
	return !in;
}




//This function's sole purpose is to instantiate a Fraction object and display its contents to the screen.
void TestFractionObjectInstantiation()
{
	Fraction fooFraction(80, 100);

	cout << "Testing a Fraction class object:";
	MakeNewLine(4);

	cout << fooFraction;
	MakeNewLine();

	system("pause");
	system("cls");
}




//This function creates two Fraction objects and add, subtracts, multiplies, and divides them respectfully and outputs
//the results as they're calculated.
void TestArithmeticOperators()
{
	cout << "Testing arithmetic operators:";
	MakeNewLine(4);

	cout << "These two objects will have arithmetic performed on them:" << "\n";
	Fraction f1(4, 8);
	Fraction f2(1, 2);
	cout << f1 << "\t\t" << f2;
	MakeNewLine();

	cout << "Addition (f1 + f2):\n";
	cout << f1 + f2;
	MakeNewLine();

	cout << "Subtraction (f1 - f2):\n";
	cout << f1 - f2;
	MakeNewLine();

	cout << "Multiplication (f1 * f2):\n";
	cout << f1 * f2;
	MakeNewLine();

	cout << "Division (f1 / f2):\n";
	cout << f1 / f2;
	MakeNewLine();

	system("pause");
	system("cls");
}





//This function creates two Fraction arrays, each three deep. For each relational operator, the Fraction objects with matching
//subscript values are tested against each other, with the results displayed to the screen.
void TestRelationalOperators()
{
	const int ARR_SIZE = 3;

	Fraction fArray1[ARR_SIZE], fArray2[ARR_SIZE];
	fArray1[0].SetFraction(1);
	fArray1[1].SetFraction(5);
	fArray1[2].SetFraction(10);
	fArray2[0].SetFraction(3);
	fArray2[1].SetFraction(5);
	fArray2[2].SetFraction(15);

	string opStr = "";
	
	cout << "Testing relational operators:";
	MakeNewLine(4);

	//test < operator
	for(int i = 0; i < ARR_SIZE; i++)
	{
		cout << fArray1[i];
		opStr = (fArray1[i] < fArray2[i]) ? "<" : "!(<)";
		cout << " " << opStr.c_str() << " ";
		cout << fArray2[i];
		MakeNewLine();
	}

	//test <= operator
	for(int i = 0; i < ARR_SIZE; i++)
	{
		cout << fArray1[i];
		opStr = (fArray1[i] <= fArray2[i]) ? "<=" : "!(<=)";
		cout << " " << opStr.c_str() << " ";
		cout << fArray2[i];
		MakeNewLine();
	}

	//test > operator
	for(int i = 0; i < ARR_SIZE; i++)
	{
		cout << fArray1[i];
		opStr = (fArray1[i] > fArray2[i]) ? ">" : "!(>)";
		cout << " " << opStr.c_str() << " ";
		cout << fArray2[i];
		MakeNewLine();
	}

	//test >= operator
	for(int i = 0; i < ARR_SIZE; i++)
	{
		cout << fArray1[i];
		opStr = (fArray1[i] >= fArray2[i]) ? ">=" : "!(>=)";
		cout << " " << opStr.c_str() << " ";
		cout << fArray2[i];
		MakeNewLine();
	}

	//test == operator
	for(int i = 0; i < ARR_SIZE; i++)
	{
		cout << fArray1[i];
		opStr = (fArray1[i] == fArray2[i]) ? "==" : "!(==)";
		cout << " " << opStr.c_str() << " ";
		cout << fArray2[i];
		MakeNewLine();
	}

	//test != operator
	for(int i = 0; i < ARR_SIZE; i++)
	{
		cout << fArray1[i];
		opStr = (fArray1[i] != fArray2[i]) ? "!=" : "!(!=)";
		cout << " " << opStr.c_str() << " ";
		cout << fArray2[i];
		MakeNewLine();
	}

	system("pause");
	system("cls");
}




//This function performs shorthand arithmetic on two Fraction objects, then displays the results to the screen.
void TestShorthandArithmeticAssignmentOperators()
{
	Fraction left(1);
	Fraction right(1, 3);

	cout << "Testing shorthand arithmetic assignment operators:";
	MakeNewLine(4);

	cout << left << "\t+=\t" << right << "\t=\t";
	left += right;
	cout << left;
	left.SetFraction(1);
	MakeNewLine();

	cout << left << "\t-=\t" << right << "\t=\t";
	left -= right;
	cout << left;
	left.SetFraction(1);
	MakeNewLine();

	cout << left << "\t*=\t" << right << "\t=\t";
	left *= right;
	cout << left;
	left.SetFraction(1);
	MakeNewLine();

	cout << left << "\t/=\t" << right << "\t=\t";
	left /= right;
	cout << left;
	left.SetFraction(1);
	MakeNewLine();

	system("pause");
	system("cls");
}




//This function tests the "Reduce" member function of the Fraction class.
//A random numerator and denominator is created and then reduced, looping twenty times. The results display after each fraction
//is reduced.
void TestReduce()
{
	const int MAX_RAND_NUM = 100;
	Fraction f;

	cout << "All of the following fractions should be as reduced as possible:";
	MakeNewLine(4);

	for(int i = 0; i < 20; i++)
	{
		f.SetFraction(rand() % (MAX_RAND_NUM + 1), rand() % (MAX_RAND_NUM + 1)); //test random numbers 0 through MAX_RAND_NUM
		cout << f;
		MakeNewLine();
	}

	system("pause");
	system("cls");
}