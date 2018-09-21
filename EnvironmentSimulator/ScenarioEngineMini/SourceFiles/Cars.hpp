#pragma once
#include <Car.hpp>
#include <ScenarioGateway.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

class Cars
{
public:
	Cars();

	// Add car
	void addCar(Car car);
	void addScenarioGateway(ScenarioGateway &scenarioGateway);

	// Get car
	Car getCar(std::string objectName);
	Car getCar(int objectId);

	// Id
	int getId(std::string objectName);
	void setObjectId(int objectId, int newObjectId);
	void setObjectId(std::string objectName, int newObjectId);

	void setExtControlled(int objectId, bool boolean);
	void setExtControlled(std::string objectName, bool boolean);

	std::string getName(int objectId);

	int getIdx(std::string objectName);
	int getIdx(int objectId);

	// Position
	roadmanager::Position getPosition(std::string objectName);
	roadmanager::Position getPosition(int objectId);	
	
	void setPosition(std::string objectName, roadmanager::Position position);
	void setPosition(int objectId, roadmanager::Position position);

	// Speed
	double getSpeed(std::string objectName);
	double getSpeed(int objectId);

	void setSpeed(std::string objectName, double speed);
	void setSpeed(int objectId, double speed);

	// Step
	void step(double dt);	
	void step(std::string objectName, double dt);
	void step(int objectId, double dt);

	// Cars itself
	int getNum();
	void printCar();
	void printCar(int objectId);


private:
	std::vector<Car> cars;
	ScenarioGateway *scenarioGateway;
};

