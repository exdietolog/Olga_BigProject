#pragma once
#include "Const.h"
class Vehicle {

public:

	//����������� �� �� ���������
	Vehicle() : totalDistance(0), totalTime(0), baseSpeed(defaultVehicleSpeed) {
		SetName(DefaultVehicleName);
	}

	//������������������� ����������� ��
	Vehicle(const char inNameCString[], double inBaseSpeed) : totalDistance(0), totalTime(0), baseSpeed(inBaseSpeed) {
		SetName(inNameCString);
	}

	//���������� ��
	virtual ~Vehicle() {

	}

	//����� ��������� ���������� �� ����� ��
	const char* const GetName() const {
		return nameCString;
	}

	//����� ��������� ���������� � �������� ��� �������
	double GetBaseSpeed() const {
		return baseSpeed;
	}

	//����� ��������� ���������� � ������� �������
	double GetToalDistance() const {
		return totalDistance;
	}

	//����� ��������� ���������� � ������� ������� ������������
	double GetTotalTime() const {
		return totalTime;
	}

	//����������� ���� ���������� �������
	//���������� true, ���� ������� ������� � false, ���� ��������� ������
	virtual bool MakeTrip(double distance) = 0;

	//����������� ����� ��������� ���������� � ������ ��������
	virtual double GetSpeed() const = 0;

	//�������� ��������� �� ����������
	bool operator< (Vehicle& rhs) const {
		if (GetSpeed() < rhs.GetSpeed()) {
			return true;
		}
		return false;
	}



	//��������� - ����� ������������ ���������� �������� � ����� ��
	static const int MAX_NAME_LENGHT = 50;

protected:
	//������� ����������� ����������
	double totalDistance;
	//������� ������ ������� ������������
	double totalTime;

private:
	//����� �������� ����� ������������ ��������
	void SetName(const char inNameCString[]) {
		int i = 0;
		for (i = 0; (inNameCString[i] != 0) && (i < MAX_NAME_LENGHT); ++i) {
			nameCString[i] = inNameCString[i];
		}
		nameCString[i] = 0;
	}

	//� - ������ ��� �������� �����
	char nameCString[MAX_NAME_LENGHT];

	//�������� ������ ������������� ��������
	double baseSpeed;

};
