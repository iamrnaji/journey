#include <iostream>
#include <string>

#ifndef CVEHICLE_H
#define CVEHICLE_H

class CVehicle

{

public: 
	CVehicle();
	CVehicle(std::string make, std::string model, std::string vehicleName, double miles = 36000, double fuelLevel = 100, char fuelType = 'G');


	std::string GetMake() const { return m_make; };
	std::string GetModel() const { return m_model; };
	std::string GetVehicleName() const { return m_vehicleName; };
	char GetFuelType() const { return m_fuelType; };
	double GetFuelLevel() const {return m_fuelLevel;};
	double GetNumMiles() const { return m_miles; };
	void SetMake(std::string make) { m_make = make; };
	void SetModel(std::string model) {m_model = model;};
	void SetVehicleName(std::string vehicleName) { m_vehicleName = vehicleName; };
	void SetFuelType(char fuelType) { m_fuelType = fuelType; };
	void SetFuelLevel(double fuelLevel) { m_fuelLevel = fuelLevel; };
	void SetNumMiles(double miles) { m_miles = miles; };


	virtual void Drive(double numMiles)=0;
	virtual void DispVehicleInfo() const=0;


protected:

	double m_miles;

	void Driving(double numMiles, double fuelRate, std::string methodTravel, std::string noFuelMesg);


private:
	string m_make;
	string m_model;
	string m_vehicleName;
	char m_fuelType;
	double m_fuelLevel;
	

};

#endif
