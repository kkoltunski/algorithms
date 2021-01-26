#include "CyclesContainer.h"
#include "ElephantsData.h"
#include "Cycle.h"

CyclesContainer::CyclesContainer(ElephantsData* _data) :
	sourceSize{ _data->getElephantsCount() },
	source{ &_data->getWorkerSequence() },
	reference{ &_data->getDirectorSequence() },
	weights{ &_data->getElephantsBodyWeights() }
{
	makePermutation();
	generate();
}

void CyclesContainer::generate() {
	std::vector<bool> truthTable(sourceSize, false);

	for (long int i = 0; i < sourceSize; ++i) {
		if (!truthTable[i]) {
			Cycle cycle;
			int x = i;

			do {
				cycle.massHandling((*weights)[permutation[x] - 1]);
				cycle.pushBackComponent(permutation[x]);

				truthTable[x] = true;
				x = (permutation[x] - 1);
			} while (!truthTable[x]);

			cycles.push_back(cycle);
		}
	}
}

void CyclesContainer::makePermutation() {
	permutation.resize(source->size());
	int index{};

	for (long int i = 0; i < sourceSize; ++i) {
		index = ((*reference)[i] - 1);
		permutation[index] = (*source)[i];
	}
}

std::list<Cycle>::iterator CyclesContainer::begin() {
	return cycles.begin();
}

std::list<Cycle>::iterator CyclesContainer::end() {
	return cycles.end();
}
