#include "Vehicle.h"
#include "Plane.h"
#include "Automobile.h"
#include "Coaches.h"
#include "Template.h"
#include <vector>



using namespace std;

void CommitRandomTrips(vector <Vehicle*>& vehicles) {
	for (int i = 0; i < vehicles.size(); i++) {
		double randomDistance = double(rand() % 20001) / 10;
		vehicles[i]->MakeTrip(randomDistance);
	}
}

	void DisplayVehicles(const vector<Vehicle*> &vehicles) {
		printf("%s     \t%s               \t%s               \t%s\n", "Name", "Speed", "Dist", "Time");
		for (int i = 0; i < vehicles.size(); ++i) {
			printf("%s     \t%fd\t%fd\t%fd\n", vehicles[i]->GetName(), vehicles[i]->GetSpeed(), vehicles[i]->GetToalDistance(), vehicles[i]->GetTotalTime());
			
		}
	}

	bool CompareDefault(Vehicle * lhs, Vehicle * rhs) {
		return *lhs < *rhs;
	}

	bool CompareTime(Vehicle * lhs, Vehicle * rhs) {
		return lhs->GetTotalTime() < rhs->GetTotalTime();
	}



int main()
{
	srand(0);
   //Векторы для ханения экземляров ТС
	//vector <Coach> coaches;
	vector <Automobile> automobile;
	vector <Plane> planes;
	vector <Coaches> coaches;

	coaches.push_back(Coaches("Coach 1", 9.));
	coaches.push_back(Coaches("Coach 2", 11.));
	coaches.push_back(Coaches("Coach 3", 10.));
	coaches.push_back(Coaches("Coach 4", 9.5));
	coaches.push_back(Coaches("Coach 5"));
	
	automobile.push_back(Automobile("Automobile 1"));
	automobile.push_back(Automobile("Automobile 2", 90.));
	automobile.push_back(Automobile("Automobile 3", 120.));
	automobile.push_back(Automobile("Automobile 3", 150.));

	planes.push_back(Plane("Plane 1", 1030.));
	planes.push_back(Plane("Plane 2", 560.));
	planes.push_back(Plane("Plane 3", 2200.));

	//Векторы указатели на объекты
	vector <Vehicle*> coachPointers;
	vector <Vehicle*> automobilePointers;
	vector <Vehicle*> planePointers;

	//Инициализация векторов указателей
	for (int i = 0; i < coaches.size(); i++) {
		coachPointers.push_back(&coaches[i]);
	}

	for (int i = 0; i < automobile.size(); i++) {
		automobilePointers.push_back(&automobile[i]);
	}

	for (int i = 0; i < planes.size(); i++) {
		planePointers.push_back(&planes[i]);
	}

	//vector<Vehicle*> vehiclePointers = coachPointers + automobilePointers + planePointers;

	CommitRandomTrips(coachPointers);
	CommitRandomTrips(automobilePointers);
	CommitRandomTrips(planePointers);

	DisplayVehicles(coachPointers);
	SeletionSort(coachPointers, 0, coachPointers.size()-1, *CompareDefault);
	
	SeletionSort(coachPointers, 0, coachPointers.size()-1, *CompareTime);

	DisplayVehicles(coachPointers);
	//DisplayVehicles(automobilePointers);
	//DisplayVehicles(planePointers);

	
}
 
