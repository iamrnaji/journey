#include <iostream>
#include <string>
using namespace std;

#include "cvehicle.h"

CVehicle::CVehicle() 
{
	m_make = "Two";
	m_model = "Legs";
	m_vehicleName = "Sam Witwicky";
	m_fuelType = 'S';
	m_fuelLevel = 85;
	m_miles = 17000;
}

CVehicle::CVehicle(std::string make, std::string model, std::string vehicleName, double miles, double fuelLevel, char fuelType)
{
	m_make = make;
	m_model = model;
	m_vehicleName = vehicleName;
	m_miles = miles;
	m_fuelLevel = fuelLevel;
	m_fuelType = fuelType;
}

void CVehicle::Driving(double numMiles, double fuelRate, std::string methodTravel, std::string noFuelMesg)
{

	cout << m_vehicleName << " :" << endl;

	cout << "\t\t" << methodTravel << " " << numMiles << " miles..." << endl;

	double fuelLost = fuelRate * numMiles;
	if (!(fuelLost >= m_fuelLevel))
	{
		m_miles += numMiles;
		m_fuelLevel -= fuelRate * numMiles;
	}
	else
	{
		double milesTraveled = m_fuelLevel / fuelRate;
		m_miles += milesTraveled;
		m_fuelLevel = 0;
		cout << noFuelMesg << endl;
		cout << "Only traveled " << milesTraveled << " miles" << endl;
	}
	

}
