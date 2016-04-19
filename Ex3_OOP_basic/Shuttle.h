#include "Ship.h"

#ifndef SHTUTTLE_H_
#define SHTUTTLE_H_

class Shuttle : public Ship
{
public:
	Shuttle::Shuttle();
	Shuttle::Shuttle(double x, double y);
	Shuttle::Shuttle(Shuttle& obj);

	
	void FTL();
	
	Shuttle::~Shuttle();
	
	void Visualize();
};


#endif