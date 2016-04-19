#include <iostream>
#include <math.h>
#include "string"

using namespace std;

#ifndef SHIP_H_
#define SHIP_H_

class Ship
{
protected:
	double x_;
	double y_;

public:
		Ship::Ship();
		Ship::Ship(double x, double y);
virtual	Ship::~Ship();

	double Ship::Getx();
	double Ship::Gety();

	void Ship::Setx(double x);
	void Ship::Sety(double y);
	///pure virtual function
	virtual void Ship::Visualize()=0;
};

#endif