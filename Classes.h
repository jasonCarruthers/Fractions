#pragma once
using namespace std;

//Description: The Fraction class contains two private member variables, mNumerator and mDenominator. The Fraction class overloads
//multiple operators (relational, arithmetic, and shorthand arithmetic operators) which makes dealing with multiple Fractions trivial.

//--------------------------------------------------------------------------
//Constructor
//--------------------------------------------------------------------------
//Fraction(int numer = 0, int denom = 1); --- Pre: Fraction object not instantiated. Post: Instantiates a Fraction object.

//--------------------------------------------------------------------------
//Accessors
//--------------------------------------------------------------------------
//double GetDecimal() const; --- Pre: N/A. Post: Returns decimal form of fraction.
//int GetNumerator() const; --- Pre: N/A. Post: Returns numerator.
//int GetDenominator() const; --- Pre: N/A. Post: Returns denominator.

//--------------------------------------------------------------------------
//Mutators
//--------------------------------------------------------------------------
//void SetFraction(int numer = 0, int denom = 1); --- Pre: N/A. Post: Sets values of mNumerator and mDenominator, the member variables.
//void Reduce(); --- Pre: There must be a numerator and denominator. Post: Fraction will be as reduced as possible.

//--------------------------------------------------------------------------
//Operator overloading
//--------------------------------------------------------------------------
//friend Fraction operator+(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns left + right.
//friend Fraction operator-(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns left - right.
//friend Fraction operator*(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns left * right.
//friend Fraction operator/(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns left / right.
//Fraction operator++(); --- Pre: N/A. Post: Calling Fraction's value will be one greater.
//Fraction operator++(int); --- Pre: N/A. Post: Calling Fraction's value will be one greater.
//Fraction operator--(); --- Pre: N/A. Post: Calling Fraction's value will be reduced by one.
//Fraction operator--(int); --- Pre: N/A. Post: Calling Fraction's value will be reduced by one.
//friend bool operator<(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns true if left < right.
//friend bool operator<=(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns true if left <= right.
//friend bool operator>(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns true if left > right.
//friend bool operator>=(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns true if left >= right.
//friend bool operator==(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns true if left == right.
//friend bool operator!=(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions, a Fraction and an int,
//																				or two integers. Post: Returns true if left != right.
//friend Fraction operator+=(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions or a Fraction and an int.
//																					Post: Sets Fraction left to left + right.
//friend Fraction operator-=(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions or a Fraction and an int.
//																					Post: Sets Fraction left to left - right.
//friend Fraction operator*=(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions or a Fraction and an int.
//																					Post: Sets Fraction left to left * right.
//friend Fraction operator/=(const Fraction &left, const Fraction &right); --- Pre: Must take two Fractions or a Fraction and an int.
//																					Post: Sets Fraction left to left / right.
//friend istream& operator>>(istream &in, Fraction &fraction); --- Pre: istream file must exist. Post: One fraction from file read
//																		and info stored in fraction object.
//friend ostream& operator<<(ostream &out, const Fraction &fraction); --- Pre: N/A. Post: Contents of fraction object displayed to screen.

class Fraction
{
public:
	Fraction(int numer = 0, int denom = 1);

	double GetDecimal() const;
	int GetNumerator() const;
	int GetDenominator() const;

	void SetFraction(int numer = 0, int denom = 1);
	void Reduce();

	friend Fraction operator+(const Fraction &left, const Fraction &right);
	friend Fraction operator-(const Fraction &left, const Fraction &right);
	friend Fraction operator*(const Fraction &left, const Fraction &right);
	friend Fraction operator/(const Fraction &left, const Fraction &right);
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);
	friend bool operator<(const Fraction &left, const Fraction &right);
	friend bool operator<=(const Fraction &left, const Fraction &right);
	friend bool operator>(const Fraction &left, const Fraction &right);
	friend bool operator>=(const Fraction &left, const Fraction &right);
	friend bool operator==(const Fraction &left, const Fraction &right);
	friend bool operator!=(const Fraction &left, const Fraction &right);
	friend Fraction operator+=(const Fraction &left, const Fraction &right);
	friend Fraction operator-=(const Fraction &left, const Fraction &right);
	friend Fraction operator*=(const Fraction &left, const Fraction &right);
	friend Fraction operator/=(const Fraction &left, const Fraction &right);
	friend istream& operator>>(istream &in, Fraction &fraction);
	friend ostream& operator<<(ostream &out, const Fraction &fraction);
private:
	int mNumerator;
	int mDenominator;
};
