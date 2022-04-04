#pragma once

class Computer
{
	const double DefaultTimeToBoot = 0.01;
public:
	Computer() : baseTimeToBoot(DefaultTimeToBoot) {}

	double GetTimeToBoot() {
		return baseTimeToBoot;
	}

protected:
	double baseTimeToBoot;


};

