#include "Time.h"
#include <iostream>
#include <sstream>
using namespace std;

bool Time::secondCheck(int s)
{
	if (s < 0 || s >= 60)
	{
		cout << "Wrong arguments to Init! = " << endl;
		return false;
	}
	else
		return true;
}

bool Time::minuteCheck(int s)
{
	if (s < 0 || s >= 60)
	{
		cout << "Wrong arguments to Init! = " << endl;
		return false;
	}
	else
		return true;
}

void Time::IncreaseSecond(int second)
{
	int a1;
	if (second + triad.getC() >= 60)
	{
		triad.augmentationB();
		if (triad.getB() >= 60)
		{
			triad.augmentationA();
			triad.setB(0);
		}
		a1 = second + triad.getC() - 60;
	}
	else
	{
		a1 = second + triad.getC();
	}
	triad.setC(0);
	for (int i = 0; i < a1; i++)
	{
		triad.augmentationC();
	}
}

void Time::IncreaseMinute(int minute)
{
	int a1;
	if (minute + triad.getB() >= 60)
	{
		triad.augmentationA();
		if (triad.getA() >= 24)
		{
			cout << "Error, 24hour = one day" << endl;
			triad.setA(0);
		}
		a1 = minute + triad.getB() - 60;
		triad.setB(a1);
	}
	else
	{
		a1 = minute + triad.getB();
	}
	triad.setB(0);
	for (int i = 0; i < a1; i++)
	{
		triad.augmentationB();
	}
}

Time::Time()
{
	triad = Triad(0, 0, 0);
}

Time::Time(int a, int b, int c)
{
	triad = Triad(a, b, c);
}
Time::Time(const Time& q)
{
	triad = q.triad;
}

Time::~Time()
{}

Time& Time::operator = (const Time& q)
{
	triad = q.triad;
	return *this;
}

Time::operator string () const
{
	stringstream ss;
	cout << triad;
	return ss.str();
}

ostream& operator << (ostream& output, const Time& q)
{
	output << string(q);
	return output;
}
istream& operator >> (istream& input, Time& q)
{
	cout << ""; input >> q.triad;
	cout << endl;
	return input;
}