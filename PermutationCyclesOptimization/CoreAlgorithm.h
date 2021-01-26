#ifndef COREALGORITHM_H
#define COREALGORITHM_H

#include "CyclesContainer.h"

class ElephantsData;

class CoreAlgorithm
{
public:
	CoreAlgorithm(ElephantsData* _data);

	void computeOptimalWork();
	long long int getOptimalWork();

private:
	long long int getResultOfMethod1(Cycle& _c);
	long long int getResultOfMethod2(Cycle& _c);

	ElephantsData* const elephants;
	CyclesContainer cycles;

	long long int computationResult;
};

#endif // COREALGORITHM_H