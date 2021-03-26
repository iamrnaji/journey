
#include <iostream>
#include <string>
using namespace std;

#include "ctruck.h"

CTruck::CTruck()
{
	SetMake("Ford");
	SetModel("F150");
	SetVehicleName("Turbofire");
	SetFuelType('D');
	SetFuelLevel(37);
	SetNumMiles(210154);
	SetTransmission('A');
	SetNumDoors(4);
	m_cabSize = 'S';
	m_bedSize = "Standard";
	m_fourWD = false;
}

CTruck::CTruck(std::string make, std::string model, std::string vehicleName,
	char transmission,
	int numDoors, double miles, double fuelLevel,
	char fuelType, char cabSize, std::string bedSize, bool fourWD)
{
	SetMake(make);
	SetModel(model);
	SetVehicleName(vehicleName);
	SetFuelType(fuelType);
	SetFuelLevel(fuelLevel);
	SetNumMiles(miles);
	SetTransmission(transmission);
	SetNumDoors(numDoors);
	m_cabSize =  cabSize;
	m_bedSize = bedSize;
	m_fourWD = fourWD;
}

void CTruck::Drive(double numMiles)
{
	Driving(numMiles, 1, "Truck Driving", "Ah, looks like you're stranded in the middle of the ocean");
}

void CTruck::DispVehicleInfo() const
{
	cout << GetVehicleName() << " info: " << endl;
	string trans;
	string fuel;
	string cab;
	string fourWD;
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
	if (GetCabSize() == 'C')
	{
		cab = "Crew";
	}
	else if (GetCabSize() == 'Q')
	{
		cab = "Quad";
	}
	else
	{
		cab = "Single";
	}
	if (GetFourWD())
	{
		fourWD = "Yes";
	}
	else
	{
		fourWD = "No";
	}
	cout << "\t\tMake: " << GetMake() << endl;
	cout << "\t\tModel: " << GetModel() << endl;
	cout << "\t\tNumber of Miles: " << GetNumMiles() << endl;
	cout << "\t\tFuel Level: " << GetFuelLevel() << "%" << endl;
	cout << "\t\tFuel Type: " << fuel << endl;
	cout << "\t\tNumber of Doors: " << GetNumberDoors() << endl;
	cout << "\t\tTransmission: " << trans << endl;
	cout << "\t\tCab Size: " << cab << endl;
	cout << "\t\tBed Size: " << GetBedSize() << endl;
	cout << "\t\tFour Wheel Drive: " << fourWD << endl;
}
