using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

template <typename Base, typename Index>		//Function for power 
Base pow(Base _base, Index _idx){
	Base temp {1};
	
	if(_idx == 0) return temp;
	else{
		for(int i = 0; i < _idx; ++i){
		temp *= _base;
		}
	}

	return temp;
}

//DEC -> x
void decToBin(unsigned int _val){
	if(_val > 1) decToBin(_val >> 1);
	cout << _val % 2;
}

void decToOct(unsigned int _val){
	if(_val > 7) decToOct(_val >> 3);
	cout << _val % 8;
}

void decToHex(unsigned int _val){
	if(_val > 15) decToHex(_val >> 4);
	char digit = ((_val % 16 > 9) ? 55 : 48) + (_val % 16);
	cout << digit;
}

//OCT -> x
void octToBin(unsigned int _val){
	string sVal = std::to_string(_val);
	int digit;
	
	digit = (sVal.back() - 48);
	sVal = sVal.erase((sVal.size() - 1), 1);
	
	
	if(sVal.size() > 0) octToBin(std::stoi(sVal));

}

int octToDec(unsigned int _val){
	string sVal = std::to_string(_val);
	int scale, digit, result {};
	
	scale = (sVal.size() - 1);
	digit = (sVal.front() - 48);
	sVal = sVal.erase(0,1);
	
	if(sVal.size() > 0) result = octToDec(std::stoi(sVal));
	
	result += digit * pow<int,int>(8,scale);
	return result;
}

void octToHex(unsigned int _val){
	
}

//HEX -> x
void hexToBin(unsigned int _val){
	
}

int hexToDec(unsigned int _val){
	std::stringstream sstream;
	int scale, digit, result {};
	string sVal;
												
	sstream << std::hex << _val;				//put hex value into sstream
	sVal = sstream.str();
											
	scale = (sVal.size() - 1);					//Prepare data for code after recur. finish
	digit = (sVal.front() - ((sVal.front() > 96) ? 87 : 48));
	sVal = "0x" + sVal.erase(0,1);
												
	sstream.str(std::string(sVal));				//Prepare value for next f.call
	sstream >> std::hex >> _val;
												
	if(sVal.size() > 2) result = hexToDec(_val);//recurension + result handshake
	
	result += digit * pow<int,int>(16,scale);
	return result;
}

void hexToOct(unsigned int _val){

}

