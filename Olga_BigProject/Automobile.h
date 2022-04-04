#include "Vehicle.h"
#include <math.h>
class Automobile : public Vehicle
{
public:
	Automobile(const char DefaultPlaneName[], double DefaultPlaneSpeed = defaultAutomobileeSpeed) : Vehicle(DefaultPlaneName, DefaultPlaneSpeed) {};

	double GetSpeed() const {

		return GetBaseSpeed() * exp(-totalDistance / 500.);
	}

	// ���������� true, ���� ������� ������� � false, ���� ��������� ������
	bool MakeTrip(double distanceOfTrip) {
		double timeOfTrip = distanceOfTrip / GetSpeed();
		
		//timeSinceLastRepair += timeOfTrip;
		totalDistance += distanceOfTrip;
		totalTime += timeOfTrip;
		return true;
	}
};

