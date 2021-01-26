#ifndef CYCLESGENERATOR_H
#define CYCLESGENERATOR_H

#include <vector>
#include <algorithm>
#include <list>
#include "Cycle.h"

class ElephantsData;

class CyclesContainer
{
public:
	CyclesContainer(ElephantsData* _data);

	std::list<Cycle>::iterator begin();
	std::list<Cycle>::iterator end();

private:
	void makePermutation();
	void generate();

	std::vector<long int>* source;
	std::vector<long int>* reference;
	std::vector<int>* weights;

	std::vector<long int> permutation;
	std::list<Cycle> cycles;
	const long int sourceSize;
};

#endif // CYCLESGENERATOR_H