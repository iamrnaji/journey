#ifndef CCAR_H
#define CCAR_H

#include <iostream>
#include <string>

#include "cvehicle.h"

class CCar : public CVehicle
{
public:
	CCar();
	CCar(std::string make, std::string model, std::string vehicleName, char transmission = 'M', int numDoors = 2,
		double miles = 57000, double fuelLevel = 63, char fuelType = 'G');

	char GetTransmission() const { return m_transmission; };
	int GetNumberDoors() const { return m_numDoors; };
	void SetTransmission(char transmission) { m_transmission = transmission; };
	void SetNumDoors(int numDoors) { m_numDoors = numDoors; };

	virtual void Drive(double numMiles);
	virtual void DispVehicleInfo() const;


private:
	char m_transmission;
	int m_numDoors;
}; 

#endif
