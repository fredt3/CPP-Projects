#include <iostream>
#include <cstdlib>
#include "Lunar.h"

using namespace std;
using namespace lunarLander;

int main()
{
	Lunar L;
	
	while(1)
	{
	L.fuelRateChange();
	
	cout <<endl<<endl<<endl;
	cout << "Current fuel rate: " << L.getFuelRate() << endl;
	cout << "Vertical Speed: " << L.getVert_Speed() << endl;
	cout << "Altitude: " << L.getAlt() << endl;
	cout << "Amount of fuel: " << L.getFuel() << endl;
	cout <<endl<<endl<<endl;
	}
	return EXIT_SUCCESS;
}
