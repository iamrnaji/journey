
#include <iostream>
#include <string>
using namespace std;

#include "ccar.h"
#include "cvehicle.h"
#include "ctruck.h"


void DisplayInfo(CVehicle& car);

int main()
{
    CCar rami;
    CTruck joe;
    DisplayInfo(rami);
    DisplayInfo(joe);
    cout << endl;

    rami.Drive(1030);
    joe.Drive(50);

    DisplayInfo(rami);
    DisplayInfo(joe);

    
}

void DisplayInfo(CVehicle& car)
{
    car.DispVehicleInfo();
}


