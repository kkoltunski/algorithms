#include "header.h"

int main(){
///////////////////////////////RECURSION EXERCISES////////////////////////////
//DEC
	cout << "DECIMAL => x\ndecToBin = "; 
	decToBin(10);
	cout << endl << "decToOct = "; 
	decToOct(1834);
	cout << endl << "decToHex = "; 
	decToHex(41970);
	cout << endl;

//OCT
	cout << "\nOCTAGONAL => x\noctToDec = " << octToDec(3452) << endl;
	cout << "octToBin = ";
	//octToBin(3452);
	octToBin(8);
	decToBin(4);

//HEX
	cout << "\n\nHEXADECIMAL => x\nhexToDec = " << hexToDec(0xA3F2) << endl;
	cout << "hexToDec = " << hexToDec(0xFFFF) << endl;
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////SORTING EXERCISES////////////////////////////
//Bubble sort
	cout << "\nBubbleSort - higher to lower : " << endl;
//	vector<int> bubbleSortIntResultVector = bubbleSort({rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand()});
	vector<int> bubbleSortIntResultVector = bubbleSort({rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand()}, 1);
	for(int i = 0; i < bubbleSortIntResultVector.size(); ++i){
		cout << "bubbleSortIntResultVector[" << i << "] = " << bubbleSortIntResultVector[i] << endl;
	}
	
	cout << "\nBubbleSort - lower to higher : " << endl;
//	vector<char> bubbleSortCharResultVector = bubbleSort({'u','p','d','v','t','g','s','a','c'}, 1);
	vector<char> bubbleSortCharResultVector = bubbleSort({'u','p','d','v','t','g','s','a','c'});
	for(int i = 0; i < bubbleSortCharResultVector.size(); ++i){
		cout << "bubbleSortCharResultVector[" << i << "] = " << bubbleSortCharResultVector[i] << endl;
	}
	
//QuickSort
	cout << "\nQuickSort - messy vector : " << endl;
	vector<float> qsVec;
	
	for(int i = 0; i < 20; ++i){
		qsVec.push_back(rand() / 2.1);
		cout << "qsVec[" << i << "] = " << qsVec[i] << endl;
	}
	
	quickSort<float>(qsVec.begin(), qsVec.end(),1);
	
	for(int i = 0; i < 20; ++i){
		cout << "qsVec[" << i << "] = " << qsVec[i] << endl;
	}

//Trees
	cout << "\nBTS, vector : " << endl;
	vector<int> bstVec;
	
	for(int i = 0; i < 10; ++i){
		bstVec.push_back(rangedRandomValue(15));
		cout << "bstVec[" << i << "] = " << bstVec[i] << endl;
	}
	
	BST<int> firstTree(bstVec);
	firstTree.showCreatedNodes();							//it is not real look of tree (this function show vector with addresses and values), real tree is in memory
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////Thue Mors Word//////////////////////////////
	//String part
	cout << "\nTHUE MORS WORD\nString operation\n";
	ThueMorsWord<string> TMword;
	
	for(long i = 0; i < 3; ++i){
		TMword.iterate();
	}
	
	TMword.showDigit();
	
//binary part
	cout << "\n\nBinary operation\n";
	ThueMorsWord<long long int> TMWlli;
	
	cout << "Val after iteration : ";
	TMWlli.iterate();
	ThueMorsWord<long long int>::binary(TMWlli.showChain());
	cout << "\nVal after iteration : ";
	TMWlli.iterate();
	ThueMorsWord<long long int>::binary(TMWlli.showChain());
	cout << "\nVal after iteration : ";
	TMWlli.iterate();
	ThueMorsWord<long long int>::binary(TMWlli.showChain());
	cout << "\nVal after iteration : ";
	TMWlli.iterate();
	ThueMorsWord<long long int>::binary(TMWlli.showChain());
	cout << "\nVal after iteration : ";
	TMWlli.iterate();
	ThueMorsWord<long long int>::binary(TMWlli.showChain());
	
	cout << endl << "On pos = 0 there is digit = " << TMWlli[0];
	cout << endl << "On pos = 1 there is digit = " << TMWlli[1];
	cout << endl << "On pos = 2 there is digit = " << TMWlli[2];
	cout << endl << "On pos = 3 there is digit = " << TMWlli[3];
	cout << endl << "On pos = 4 there is digit = " << TMWlli[4];
	cout << endl << "On pos = 5 there is digit = " << TMWlli[5];
	cout << endl << "On pos = 6 there is digit = " << TMWlli[6];
	cout << endl << "On pos = 7 there is digit = " << TMWlli[7];
	cout << endl << "On pos = 1000000000000000 there is digit = " << TMWlli[1000000000000000] << endl;
//////////////////////////////////////////////////////////////////////////////
	
	return 0;
}
