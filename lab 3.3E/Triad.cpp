#include "Triad.h"
#include <sstream>
#include <iostream>

using namespace std;

void Triad::augmentationA()
{
	a += 1;
}

void Triad::augmentationB()
{
	b += 1;
}

void Triad::augmentationC()
{
	c += 1;
}

Triad::Triad()
{
	a = 0;
	b = 0;
	c = 0;
}
Triad::Triad(int aa, int bb, int cc)
{
	a = aa;
	b = bb;
	c = cc;
}

Triad::Triad(const Triad& q)
{
	a = q.a;
	b = q.a;
	c = q.c;
}
Triad::~Triad()
{}

Triad& Triad::operator = (const Triad& q)
{
	a = q.a;
	b = q.b;
	c = q.c;
	return *this;
}
Triad::operator string () const
{
	stringstream ss;
	ss << " hour = " << a << endl;
	ss << " minute = " << b << endl;
	ss << " second = " << c << endl;
	return ss.str();
}

ostream& operator << (ostream& output, const Triad& q)
{
	output << string(q);
	return output;
}
istream& operator >> (istream& input, Triad& q)
{
	cout << " hour = "; input >> q.a;
	cout << " minute = "; input >> q.b;
	cout << " second = "; input >> q.c;
	cout << endl;
	return input;
}