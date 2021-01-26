#ifndef ELEPHANTSDATA_H
#define ELEPHANTSDATA_H

#include <vector>
#include <exception>

class ElephantsData
{
public:
	void initializeData(long int _elephantCount);
	void assignElephantWeight(size_t _pos, int _elephantWeight);
	void setWorkersSequence(std::vector<long int>& _vector);
	void setDirectorSequence(std::vector<long int>& _vector);
	long int getElephantsCount();
	int getElephantsLowestWeight();
	std::vector<int>& getElephantsBodyWeights();
	std::vector<long int>& getWorkerSequence();
	std::vector<long int>& getDirectorSequence();

private:
	long int count = 0;
	int lowestElephantWeight = INT_MAX;
	std::vector<int> bodyWeights;
	std::vector<long int> workersSequence;
	std::vector<long int> directorSequence;

	enum class countExtremas : long int { min = 2, max = 1000000 };
	enum class weightExtremas : int { min = 100, max = 6500 };
};

#endif // ELEPHANTSDATA_H