#include "CoreAlgorithm.h"
#include "ElephantsData.h"
#include "CyclesContainer.h"

CoreAlgorithm::CoreAlgorithm(ElephantsData* _data) :
	elephants{ _data }, cycles{ elephants }, computationResult{}
{
}

void CoreAlgorithm::computeOptimalWork() {
	for (auto cycle : cycles) {
		if (cycle.getSize() > 1) {
			auto method1Result = getResultOfMethod1(cycle);
			auto method2Result = getResultOfMethod2(cycle);
			
			if (method1Result < method2Result) {
				computationResult += method1Result;
			}
			else {
				computationResult += method2Result;
			}
		}
	}
}

long long int CoreAlgorithm::getResultOfMethod1(Cycle& _c) {
	return (_c.getMassSum() + (_c.getLowestMass() * (_c.getSize() - 2)));
}

long long int CoreAlgorithm::getResultOfMethod2(Cycle& _c) {
	return (_c.getMassSum() + _c.getLowestMass() + 
				( elephants->getElephantsLowestWeight() * (_c.getSize() + 1)));
}

long long int CoreAlgorithm::getOptimalWork() {
	return computationResult;
}