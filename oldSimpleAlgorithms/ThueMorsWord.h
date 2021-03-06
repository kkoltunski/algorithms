#ifndef THUEMORSWORD_H
#define THUEMORSWORD_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<typename ChainType>											//Not so clever use of template
class ThueMorsWord
{	
		int firstDigit;
		ChainType chain;
		int nextShift = 1;
		
		ChainType removeMinus(ChainType &val){							//bit negation - because value is "-" after iterate()
			ChainType abs = ~val;										//i dont know why in iterate() it doesnt work...
			return abs;	
		}
		
	public:
		ThueMorsWord(char _fdig = 1) : firstDigit{_fdig}{
			chain = firstDigit;
			chain = chain << 1;
		}

		ChainType showChain(){							
			return removeMinus(chain);
		}
		void iterate(){													//add negated chain of bits to actual chain
			ChainType temp = ~chain;
			chain <<= nextShift;
			chain = (chain | temp);
			nextShift <<= 1;
		}
		static void binary(ChainType val);
		
		char operator[](long long int _pos);
};

template<typename ChainType>											//conversion to binnary 
void ThueMorsWord<ChainType>::binary(ChainType _val){
	if(_val > 1) binary(_val >> 1);
	cout << _val % 2;
}

template<typename ChainType>
char ThueMorsWord<ChainType>::operator[](long long int _posToCheck){
	/*ChainType tempOrg = (removeMinus(chain) >> (_pos));	//checking on real bits
	ChainType tempCpy = ((tempOrg >> 1) << 1);
	return (tempCpy < tempOrg ? 'Y' : 'X');*/
	
	string binaryResult{""};											//Thue-Morse algorithm
	int onesCounter {};
	
	while(_posToCheck > 0){
		binaryResult += std::to_string(_posToCheck % 2);
		_posToCheck >>= 1;
	}
	
	for(auto bit : binaryResult){
		(bit == '1' ? onesCounter++ : onesCounter = onesCounter);
	}
	
	return (onesCounter % 2 ? 'Y' : 'X');
}

template<>																//template specialization for string
class ThueMorsWord<string>
{	
		char firstDigit;
		string chain;
	
	public:
		ThueMorsWord(char _fdig = 'X') : firstDigit{_fdig}{	
			chain = firstDigit;
			chain += (firstDigit + 1);
		}
		
		void showDigit(long long unsigned int _pos = string::npos){		//options to show created chain
			if((_pos < 0) || (_pos > string::npos)) std::cout << "wrong pos" << std::endl;
			if((_pos < 0) || (_pos > string::npos))	std::cout << chain[_pos];
			else if(_pos == string::npos) std::cout << chain;
		}
		
		size_t showSize(){
			return chain.size();	
		}	
		void iterate(){													//add negated chain to actual chain
			string temp {};
			
			for(int i = 0; i < chain.size(); i++){
				(chain[i] == firstDigit ? temp += (firstDigit + 1) : temp += firstDigit);
			}		
			
			chain += temp;
		}
};
#endif
