#pragma once
#include <string>
#include "Object.h"
using namespace std;

class Triad : public Object
{
private:
	int a;
	int b;
	int c;
public:
	int getA() const { return a; }
	int getB() const { return b; }
	int getC() const { return c; }
	void setA(int a) { this->a = a; }
	void setB(int b) { this->b = b; }
	void setC(int c) { this->c = c; }

	Triad(); // конструктор за умовчанням
	Triad(int, int, int); // конструктор ініціалізації
	Triad(const Triad&); //копіювання
	~Triad();
	void augmentationA();
	void augmentationB();
	void augmentationC();


	Triad& operator = (const Triad&); // присвоєння
	friend istream& operator >> (istream&, Triad&); //введення з клавіатури
	friend ostream& operator << (ostream&, const Triad&); //вивід на екран
	operator string() const; //приведення типу – перетворення у літерний рядок
};