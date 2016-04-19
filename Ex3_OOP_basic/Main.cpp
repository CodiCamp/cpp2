#include "Ship.h"
#include "Student.h"
#include "Shuttle.h"

int main()
{
	//Ship sh(3.3,6.7); //x = 2.5, y=2.7
	
	Ship* sh = new Shuttle(1.2,3.2);
	
	Shuttle* sh1 = new Shuttle(1.4, 6.2);
	
	Shuttle* sh2 = new Shuttle(*sh1);


	cout << sh2->Getx() << "  " << sh2->Gety();
	//sh->Visualize();

//	delete shuttle;

	return 0;
}