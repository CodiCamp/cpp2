#include "Ship.h"

Ship::Ship()
{
	x_ = 2.5;
	y_ = 2.7;

	cout << "Base Ship Constructor " << endl;
}

Ship::Ship(double x, double y)
{
	x_ = x;
	y_ = y;
	cout << "Base Ship Constructor with parameters" << endl;

}

Ship::~Ship()
{
	cout << "Base destructor" << endl;

}
double Ship::Getx()
{
	return x_;
}

double Ship::Gety()
{
	return y_;
}

void Ship::Setx(double x)
{
	x_ = x;
}

void Ship::Sety(double y)
{
	y_ = y;
}
  void Ship::Visualize()
{
	
}