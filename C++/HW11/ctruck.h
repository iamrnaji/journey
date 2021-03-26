#ifndef CTRUCK_H
#define CTRUCK_H


#include <iostream>
#include <string>


#include "ccar.h"
#include "cvehicle.h"

class CTruck : public CCar
{
public:
	CTruck();
	CTruck(std::string make, std::string model, std::string vehicleName,
		char transmission = 'A',
		int numDoors = 4, double miles = 97350, double fuelLevel = 98,
		char fuelType = 'D', char cabSize = 'C', std::string bedSize = "Short", bool fourWD = false);

	char GetCabSize() const { return m_cabSize; };
	std::string GetBedSize()  const { return m_bedSize; };
	bool GetFourWD() const { return m_fourWD; };
	void SetCabSize(char cabSize) { m_cabSize = cabSize; };
	void SetBedSize(std::string bedSize) { m_bedSize = bedSize; };
	void SetFourWD(bool fourWD) { m_fourWD = fourWD; };

	virtual void Drive(double numMiles);
	virtual void DispVehicleInfo() const;


private:
	char m_cabSize;
	std::string m_bedSize;
	bool m_fourWD;
};

#endif
