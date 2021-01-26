#include "ElephantsData.h"

void ElephantsData::initializeData(long int _elephantCount) {
	if (static_cast<long int>(countExtremas::min) <= _elephantCount &&
		_elephantCount <= static_cast<long int>(countExtremas::max))
	{
		count = _elephantCount;
		bodyWeights.resize(count);
		workersSequence.resize(count);
		directorSequence.resize(count);
	}
	else 
	{
		throw std::exception{"Wrong input data."};
	}
}

void ElephantsData::assignElephantWeight(size_t _pos, int _elephantWeight) {
	if (static_cast<int>(weightExtremas::min) <= _elephantWeight &&
		_elephantWeight <= static_cast<int>(weightExtremas::max))
	{
		if (_elephantWeight < lowestElephantWeight) {
			lowestElephantWeight = _elephantWeight;
		}
		bodyWeights[_pos] = _elephantWeight;
	}
	else
	{
		throw std::exception{ "Wrong input data." };
	}
}

void ElephantsData::setWorkersSequence(std::vector<long int>& _vector) {
	workersSequence = std::move(_vector);
}

void ElephantsData::setDirectorSequence(std::vector<long int>& _vector) {
	directorSequence = std::move(_vector);
}

long int ElephantsData::getElephantsCount() {
	return count;
}

int ElephantsData::getElephantsLowestWeight() {
	return lowestElephantWeight;
}

std::vector<int>& ElephantsData::getElephantsBodyWeights() {
	return bodyWeights;
}

std::vector<long int>& ElephantsData::getWorkerSequence() {
	return workersSequence;
}

std::vector<long int>& ElephantsData::getDirectorSequence() {
	return directorSequence;
}