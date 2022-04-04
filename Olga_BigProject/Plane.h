#include "Vehicle.h"
#include "Computer.h"
class Plane : public Vehicle, Computer
{

	double inBasePrice;

	const double MAX_FLY_TIME = 2000;
	double timeSinceLastRepair;

public:
	Plane(const char DefaultPlaneName[], double DefaultPlaneSpeed) : Vehicle(DefaultPlaneName, DefaultPlaneSpeed) {};

	// ¬озвращает true, если поездка удачна€ и false, если случилась авари€
	virtual bool MakeTrip(double distanceOfTrip) {
		double timeOfTrip = distanceOfTrip / GetSpeed() + GetTimeToBoot();
		if (timeSinceLastRepair + timeOfTrip > MAX_FLY_TIME) {
			return false;
		}
		timeSinceLastRepair += timeOfTrip;
		totalDistance += distanceOfTrip;
		totalTime += timeOfTrip;
		return true;
	}

	//јбстрактный метод получени€ информации о текущей скорости
	double GetSpeed() const {
		return GetBaseSpeed();
	}

	void Repair() {
		timeSinceLastRepair = 0;
	}

	double GetTimeSinceLastRepair() const {
		return timeSinceLastRepair;
	}

	const double DefaultTimeToBoot = 0.01;

protected:

	void ComputerUpdate(double newTimeToBoot) {
		baseTimeToBoot = newTimeToBoot;
	}

};


