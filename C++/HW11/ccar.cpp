#include <iostream>
#include <string>
using namespace std;

#include "ccar.h"

CCar::CCar() 

{
	SetMake("Honda");
	SetModel("Civic");
	SetVehicleName("Rumble");
	SetFuelType('G');
	SetFuelLevel(75);
	SetNumMiles(53000);
	m_transmission = 'M';
	m_numDoors = 2;
}

CCar::CCar(std::string make, std::string model, std::string vehicleName, char transmission, int numDoors,
	double miles, double fuelLevel, char fuelType)
{
	SetMake(make);
	SetModel(model);
	SetVehicleName(vehicleName);
	SetFuelType(transmission);
	SetFuelLevel(fuelLevel);
	SetNumMiles(miles);
	m_transmission = transmission;
	m_numDoors = numDoors;
}

void CCar::Drive(double numMiles)
{
	Driving(numMiles, .4, "Car Driving", "Ah, looks like you're stranded in the middle of the ocean");
}

void CCar::DispVehicleInfo() const
{
	string trans;
	string fuel;
	if (GetTransmission() == 'A')
	{
		trans = "Automatic";
	}
	else
	{
		trans = "Manual";
	}
	if (GetFuelType() == 'G')
	{
		fuel = "Gas";
	}
	else
	{
		fuel = "Diesel";
	}
	cout << "\t\tMake: " << GetMake() << endl;
	cout << "\t\tModel: " << GetModel() << endl;
	cout << "\t\tNumber of Miles: " << GetNumMiles() << endl;
	cout << "\t\tFuel Level: " << GetFuelLevel() << "%" << endl;
	cout << "\t\tFuel Type: " << fuel << endl;
	cout << "\t\tNumber of Doors: " << GetNumberDoors() << endl;
	cout << "\t\tTransmission: " << trans << endl;
} 
