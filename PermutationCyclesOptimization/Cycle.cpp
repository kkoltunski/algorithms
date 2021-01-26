#include "Cycle.h"

void Cycle::massHandling(int _mass) {
	if (_mass < lowestMass) {
		lowestMass = _mass;
	}

	massSum += _mass;
}

void Cycle::pushBackComponent(long int _component) {
	components.push_back(_component);
}

long int Cycle::getSize() {
	return components.size();
}

long long int Cycle::getMassSum() {
	return massSum;
}

int Cycle::getLowestMass() {
	return lowestMass;
}