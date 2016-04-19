#include "Shuttle.h"

Shuttle::Shuttle()
{
	cout << "Base Shuttle Constructor " << endl;

};
///this is a constructor with 2 parameters.

Shuttle::Shuttle(double x, double y) 
{
	Shuttle::x_ = x;
	Shuttle::y_ = y;
	cout << "Base Shuttle Constructor with parameters" << endl;

}
Shuttle::Shuttle(Shuttle& obj)
{
	x_ = obj.x_;
	y_ = obj.y_;
}


void Shuttle::FTL()
{
	cout << "Light Years to travel: " <<Shuttle::Getx() * Shuttle::Gety() << endl;
}

void Shuttle::Visualize()
{
	cout << "***:***" << endl;
}
Shuttle::~Shuttle()
{
	cout << "shuttle destructor" << endl;

};