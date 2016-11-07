//Class invariant: (class Fraction) mNumerator is the numerator value of the Fraction; mDenominator is the denominator value
//of the Fraction. Fractions will always be in their most reduced form (any time a Fraction is modified, it's also reduced.)


#include <iostream>
#include <fstream>
#include <cassert>
#include "Classes.h"
using namespace std;


//--------------------------------------------------------------------------
//Constructor
//--------------------------------------------------------------------------
//This is the constructor of the Fraction class. The default fraction is 0/1.
//This fraction calls the "SetFraction" function to actually set the values of the numerator and denominator,
//since otherwise there would have been duplicate code. (see SetFraction)
Fraction::Fraction(int numer, int denom)
{
	SetFraction(numer, denom);
}





//--------------------------------------------------------------------------
//Accessors
//--------------------------------------------------------------------------
//This function returns the a double who's value is the decimal version of the calling object's fraction
double Fraction::GetDecimal() const
{
	return static_cast<double>(mNumerator) / static_cast<double>(mDenominator);
}





//Returns the numerator. This function isn't necessary because all of the functions that use the mNumerator member variable of
//the Fraction class are either member functions themselves or friends of Fraction. This function is here in the event that
//a global function needs access to the numerator.
int Fraction::GetNumerator() const
{
	return mNumerator;
}




//Same thing as "GetNumerator" except it returns the mDenominator.
int Fraction::GetDenominator() const
{
	return mDenominator;
}




//--------------------------------------------------------------------------
//Mutators
//--------------------------------------------------------------------------
//This function is similar to the constructor, except it's callable after initializing a Fraction object. Useful for
//changing the values of a fraction after it's been created. It takes in numer and denom as parameters, which become
//the new values. If the denom param is zero, then mDenominator doesn't change. After setting the new values of the
//fraction, it's reduced to its smallest form.
void Fraction::SetFraction(int numer, int denom)
{
	mNumerator = numer;
	mDenominator = (denom == 0) ? mDenominator : denom;
	Reduce();
}




//This function reduces the calling object's value to its smallest form (reduces fractions).
//First this function checks if both the numerator and denominator are evenly divisible by two, and if not
//checks for three and increasing odd numbers until the smaller of the two fraction components is reached (fraction
//components being the numerator and denominator). If the fraction can successfully be reduced, then its values are
//divided by the minimizer variable and recursion ensues. Otherwise, the fraction can't be reduced and this function ends.
void Fraction::Reduce()
{
	int minimizer = 1;
	int smallest = (abs(mNumerator) < abs(mDenominator)) ? abs(mNumerator) : abs(mDenominator);

	if( !(abs(mNumerator) % 2) && !(abs(mDenominator) % 2) )		//check if numer and denom are divisible by 2
		minimizer = 2;
	else															//check if numer and denom are divisible by any odd numbers
	{
		for(int i = 3; i <= smallest; i+=2)
		{
			if( !(abs(mNumerator) % i) && !(abs(mDenominator) % i) )
			{
				minimizer = i;
				break;
			}
		}
	}

	if( minimizer > 1 )
		SetFraction(mNumerator/minimizer, mDenominator/minimizer);
	else
		return;
}




//--------------------------------------------------------------------------
//Operator overloading
//--------------------------------------------------------------------------
//Takes two Fraction objects as parameters, left and right. Adds the fractions together, reduces, then returns the result.
Fraction operator+(const Fraction &left, const Fraction &right)
{
	Fraction temp(left.mNumerator * right.mDenominator +
		right.mNumerator * left.mDenominator,
		left.mDenominator * right.mDenominator);
	temp.Reduce();
	return temp;
}




//Takes two Fraction objects as parameters, left and right. Subtracts right from left, reduces, then returns the result.
Fraction operator-(const Fraction &left, const Fraction &right)
{
	Fraction temp(left.mNumerator * right.mDenominator -
		right.mNumerator * left.mDenominator,
		left.mDenominator * right.mDenominator);
	temp.Reduce();
	return temp;
}




//Takes two Fraction objects as parameters, left and right. Multiplies the fractions together, reduces, then returns the result.
Fraction operator*(const Fraction &left, const Fraction &right)
{
	Fraction temp(left.mNumerator * right.mNumerator,
		left.mDenominator * right.mDenominator);
	temp.Reduce();
	return temp;
}




//Takes two Fraction objects as parameters, left and right. Divides Fraction left by Fraction right, reduces, then returns the result.
Fraction operator/(const Fraction &left, const Fraction &right)
{
	Fraction temp(left.mNumerator * right.mDenominator,
		left.mDenominator * right.mNumerator);
	temp.Reduce();
	return temp;
}




//This function increases the calling Fraction's numerator by 1*mDenominator, then returns the result.
//This is the pre-increment version
Fraction Fraction::operator++()
{
	mNumerator += mDenominator;
	return *this;
}




//This function increases the calling Fraction's numerator by 1*mDenominator, then returns the fraction before it was modified.
//This is the post-increment version
Fraction Fraction::operator++(int)
{
	Fraction temp(mNumerator, mDenominator);
	temp.mNumerator += mDenominator;
	return temp;
}




//This function decreases the calling Fraction's numerator by 1*mDenominator, then returns the result.
//This is the pre-decrement version
Fraction Fraction::operator--()
{
	mNumerator -= mDenominator;
	return *this;
}




//This function decreases the calling Fraction's numerator by 1*mDenominator, then returns the fraction before it was modified.
//This is the post-decrement version
Fraction Fraction::operator--(int)
{
	Fraction temp(mNumerator, mDenominator);
	temp.mNumerator -= mDenominator;
	return temp;
}




//This function takes two Function objects as params, left and right. Returns true if left is less than right.
bool operator<(const Fraction &left, const Fraction &right)
{
	if( left.mNumerator * right.mDenominator < right.mNumerator * left.mDenominator )
		return true;
	return false;
}




//This function takes two Function objects as params, left and right. Returns true if left is less than or equal to right.
bool operator<=(const Fraction &left, const Fraction &right)
{
	if( left.mNumerator * right.mDenominator <= right.mNumerator * left.mDenominator )
		return true;
	return false;
}




//This function takes two Function objects as params, left and right. Returns true if left is greater than right.
bool operator>(const Fraction &left, const Fraction &right)
{
	if( left.mNumerator * right.mDenominator > right.mNumerator * left.mDenominator )
		return true;
	return false;
}




//This function takes two Function objects as params, left and right. Returns true if left is greater than or equal to right.
bool operator>=(const Fraction &left, const Fraction &right)
{
	if( left.mNumerator * right.mDenominator >= right.mNumerator * left.mDenominator )
		return true;
	return false;
}




//This function takes two Function objects as params, left and right. Returns true if left is equivalent to right.
bool operator==(const Fraction &left, const Fraction &right)
{
	if( left.mNumerator * right.mDenominator == right.mNumerator * left.mDenominator )
		return true;
	return false;
}




//This function takes two Function objects as params, left and right. Returns true if left is not equivalent to right.
bool operator!=(const Fraction &left, const Fraction &right)
{
	if( left.mNumerator * right.mDenominator != right.mNumerator * left.mDenominator )
		return true;
	return false;
}




//This function takes two Function objects as params, left and right. Increases left by the value of right, reduces left fraction,
//then returns that fraction which becomes the new value for the Fraction that was the left param.
Fraction operator+=(const Fraction &left, const Fraction &right)
{
	Fraction temp( left.mNumerator * right.mDenominator + right.mNumerator * left.mDenominator,
					left.mDenominator * right.mDenominator );
	temp.Reduce();
	return temp;
}




//This function takes two Function objects as params, left and right. Subtracts right from left, calls Reduce(),
//then returns the result which becomes the new value for the Fraction that was the left param.
Fraction operator-=(const Fraction &left, const Fraction &right)
{
	Fraction temp( left.mNumerator * right.mDenominator - right.mNumerator * left.mDenominator,
					left.mDenominator * right.mDenominator );
	temp.Reduce();
	return temp;
}




//This function takes two Function objects as params, left and right. Multiplies left and right together, calls Reduce(),
//then returns the result which becomes the new value for the Fraction that was the left param.
Fraction operator*=(const Fraction &left, const Fraction &right)
{
	Fraction temp( left.mNumerator * right.mNumerator, left.mDenominator * right.mDenominator );
	temp.Reduce();
	return temp;
}




//This function takes two Function objects as params, left and right. Divides left by right, calls Reduce(),
//then returns the result which becomes the new value for the Fraction that was passed in as the left param.
Fraction operator/=(const Fraction &left, const Fraction &right)
{
	Fraction temp( left.mNumerator * right.mDenominator, left.mDenominator * right.mNumerator );
	temp.Reduce();
	return temp;
}




//Insertion operator. Takes an istream in as the left param and a Fraction fraction as the right param.
//The variable "in" is browsed linearly until a carriage return is hit (because that signifies the end of a fraction in the
//file that's being read). The data from the fraction that is read from the file is stored in the "fraction" variable, which
//is pass-by-referrence so its value changes.
//-----Note to self----- in.peek() checks the next character in a file
istream& operator>>(istream &in, Fraction &fraction)
{
	//the numerator of "fraction" is set to GARBAGE_VALUE because the logic of this function checks to see if the
	//numerator has been changed or not; if its value stays zero then this function would have problems reading fractions
	//of 0/1 or just 0 from files.
	const int GARBAGE_VALUE = -999999;

	int tempInt = GARBAGE_VALUE;
	char tempChar = '\0';
	int wholeNumVal = 0;
	int wholeNumSign = 1;
	fraction.mNumerator = GARBAGE_VALUE;

	do
	{
		//read next integer
		in >> tempInt;

		if(in.peek() == '+')
		{
			//this number is a whole number
			wholeNumVal = tempInt;
			wholeNumSign = (wholeNumVal / abs(wholeNumVal) == -1) ? -1 : 1;

			//read next char (the '+')
			in >> tempChar;
		}
		else if(in.peek() == '/')
		{
			//this number is the numerator
			fraction.mNumerator = tempInt;

			//read next char (the '/')
			in >> tempChar;
		}
		else
		{
			
			if(fraction.mNumerator == GARBAGE_VALUE)	//the result is just a whole number
				fraction.mNumerator = tempInt;
			else										//otherwise this number is the denominator
				fraction.mDenominator = tempInt;
		}
	} while( in && in.peek() != '\n' );

	if( !in || wholeNumVal != 0 )
		fraction.mNumerator = fraction.mNumerator * wholeNumSign + wholeNumVal * fraction.mDenominator;

	fraction.Reduce();

	return in;
}




//This function takes an ostream object "out" and a Fraction object "fraction"
//Sets up "out" so that it will display the contents of fraction to the screen after this function returns.
//Output differs based on fraction's form: wholeNum, wholeNume+numer/denom, numer/denom
ostream& operator<<(ostream &out, const Fraction &fraction)
{
	int wholeNum = 0;

	if( abs(fraction.mDenominator > 1) && static_cast<int>(abs(fraction.mNumerator) / abs(fraction.mDenominator)) >= 1 )
	{
		wholeNum = static_cast<int>(fraction.mNumerator / fraction.mDenominator);
		out << wholeNum;
		if( abs(wholeNum) * abs(fraction.mDenominator) < abs(fraction.mNumerator) )
			out << "+" << abs(fraction.mNumerator) - abs(wholeNum) * abs(fraction.mDenominator);
	}
	else
		out << fraction.mNumerator;

	if( fraction.mDenominator > 1 && abs(wholeNum) * abs(fraction.mDenominator) < abs(fraction.mNumerator) )
		out << "/" << fraction.mDenominator;

	return out;
}