#include "Vehicle.h"
#include "math.h"
class Coaches: public Vehicle
{
	const double MAX_DISTANCE= 0;
	double timeSinceLastRepair;
public:
	Coaches(const char DefaultPlaneName[], double DefaultPlaneSpeed = DefaultCoachSpeed) : Vehicle(DefaultPlaneName, DefaultPlaneSpeed) {};

	double GetSpeed() const {

		return GetBaseSpeed() * exp(-totalTime / 500.);
	}

	// Возвращает true, если поездка удачная и false, если случилась авария
	bool MakeTrip(double distanceOfTrip) {
		double timeOfTrip = distanceOfTrip / GetSpeed();
		if (totalDistance > MAX_DISTANCE) {
			return false;
		}
		//timeSinceLastRepair += timeOfTrip;
		totalDistance += distanceOfTrip;
		totalTime += timeOfTrip;
		return true;
	}
};

