#ifndef CYCLE_H
#define CYCLE_H

#include <list>

class Cycle
{
public:
	void massHandling(int _mass);
	void pushBackComponent(long int _component);
	long int getSize();
	long long int getMassSum();
	int getLowestMass();

private:
	int lowestMass = INT_MAX;
	long long int massSum = 0;
	
	std::list<long int> components;
};

#endif // CYCLE_H