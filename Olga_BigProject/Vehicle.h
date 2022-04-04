#pragma once
#include "Const.h"
class Vehicle {

public:

	//Конструктор ТС по умолчанию
	Vehicle() : totalDistance(0), totalTime(0), baseSpeed(defaultVehicleSpeed) {
		SetName(DefaultVehicleName);
	}

	//Параметризированный конструктор ТС
	Vehicle(const char inNameCString[], double inBaseSpeed) : totalDistance(0), totalTime(0), baseSpeed(inBaseSpeed) {
		SetName(inNameCString);
	}

	//Деструктор ТС
	virtual ~Vehicle() {

	}

	//Метод получения информации об имени ТС
	const char* const GetName() const {
		return nameCString;
	}

	//Метод получения информации о скорости при покупке
	double GetBaseSpeed() const {
		return baseSpeed;
	}

	//Метод получения информации о текущем пробеге
	double GetToalDistance() const {
		return totalDistance;
	}

	//Метод получения информации о текущем времени эксплуатации
	double GetTotalTime() const {
		return totalTime;
	}

	//Абстрактный мето совершения поездки
	//Возвращает true, если поездка удачная и false, если случилась авария
	virtual bool MakeTrip(double distance) = 0;

	//Абстрактный метод получения информации о ткущей скорости
	virtual double GetSpeed() const = 0;

	//Оператор сравнения по умоолчанию
	bool operator< (Vehicle& rhs) const {
		if (GetSpeed() < rhs.GetSpeed()) {
			return true;
		}
		return false;
	}



	//Константа - общее максимальное количество символов в имени ТС
	static const int MAX_NAME_LENGHT = 50;

protected:
	//Счетчик пройденного расстояния
	double totalDistance;
	//счетчик общего времени эксплуатации
	double totalTime;

private:
	//Метод усановки имени трансортного средства
	void SetName(const char inNameCString[]) {
		int i = 0;
		for (i = 0; (inNameCString[i] != 0) && (i < MAX_NAME_LENGHT); ++i) {
			nameCString[i] = inNameCString[i];
		}
		nameCString[i] = 0;
	}

	//С - строка для хранения имени
	char nameCString[MAX_NAME_LENGHT];

	//Скорость нового транспортного средства
	double baseSpeed;

};
