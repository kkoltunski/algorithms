#include "ElephantsData.h"
#include "FileParser.h"
#include "CoreAlgorithm.h"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc > 1 && argc < 3) {
		try {
			ElephantsData elephants;
			FileParser documentReader(argv[1], &elephants);
			documentReader.openFile();
			documentReader.parseFile();

			CoreAlgorithm algorithm(&elephants);
			algorithm.computeOptimalWork();
			std::cout << "Result = " << algorithm.getOptimalWork() << std::endl;
		}
		catch (std::exception _e) {
			std::cout << _e.what() << std::endl;
		}
	}
	return 0;
}