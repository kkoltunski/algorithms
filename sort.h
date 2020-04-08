#include "Trees.h"

extern int randomVal(int _upRange, int _botRange);

//Bubble sort - argument passed as initializer list to object
template<typename T>
vector<T> bubbleSort(const std::initializer_list<T> &_inputL, bool _dir = 0) throw(std::out_of_range){
	vector<T> tabVec {_inputL};											//result vector
	auto nextObj = (_dir ? (tabVec.end() - 2) : (tabVec.begin() + 1));	//next object depend on direction
	T temp {};															//temporary value used to swap elements
	unsigned short ct = 0;												//value to count "no change" pairs

	if(std::numeric_limits<unsigned short>::max() < tabVec.size())		//if too many elements in initializer list then throw exception
		throw(std::out_of_range("counter val. is to low"));
							
	if(tabVec.size() > 1){												//one element has not to be sort
		if(_dir){														//higher -> lower direction
			for(auto i = (tabVec.end() - 1); (ct <= (tabVec.size() - 1)); --i, --nextObj){	//swap elements
				if(nextObj == (tabVec.begin() - 1)){					//if iterator to next object is out of bound that mean we need to go back
					i = tabVec.end();
					nextObj = i - 1;
				}
			
				if(*i > *nextObj){										//if values on iterators positions are in wrong direction => swap them and reset counter
					temp = *nextObj;
					*nextObj = *i;
					*i = temp;
					ct = 0;
				}
				else ++ct;												//increase counter	
			}
		}
		else{															//lowe -> higher direction
			for(auto i = tabVec.begin(); (ct <= (tabVec.size() - 1)); ++i, ++nextObj){	//swap elements
				if(nextObj == tabVec.end()){							//if iterator to next object is out of bound that mean we need to go back
					i = tabVec.begin();
					nextObj = i + 1;
				}
			
				if(*i > *nextObj){										//if values on iterators positions are in wrong direction => swap them and reset counter
					temp = *nextObj;
					*nextObj = *i;
					*i = temp;
					ct = 0;
				}
				else ++ct;												//increase counter
			}	
		}
	}
	return tabVec;
}

//Bubble sort - argument passed as address to object - have to be non-const bc will be operated on orginal vector
template<typename T>
vector<T>& bubbleSort(vector<T> &_vecAdr, bool _dir = 0) throw(std::out_of_range){
	auto nextObj = (_dir ? (_vecAdr.end() - 2) : (_vecAdr.begin() + 1));	//next object depend on direction
	T temp {};															//temporary value used to swap elements
	unsigned short ct = 0;												//value to count "no change" pairs

	if(std::numeric_limits<unsigned short>::max() < _vecAdr.size())		//if too many elements in initializer list then throw exception
		throw(std::out_of_range("counter possible value is to low"));					
	
	if(_vecAdr.size() > 1){												//one element has nt to be sort
		if(_dir){														//higher -> lower direction
			for(auto i = (_vecAdr.end() - 1); (ct <= (_vecAdr.size() - 1)); --i, --nextObj){	//swap elements
				if(nextObj == (_vecAdr.begin() - 1)){					//if iterator to next object is out of bound that mean we need to go back
					i = _vecAdr.end();
					nextObj = i - 1;
				}
				
				if(*i > *nextObj){										//if values on iterators positions are in wrong direction => swap them and reset counter
					temp = *nextObj;
					*nextObj = *i;
					*i = temp;
					ct = 0;
				}
				else ++ct;												//increase counter	
			}
		}
		else{																//lowe -> higher direction
			for(auto i = _vecAdr.begin(); (ct <= (_vecAdr.size() - 1)); ++i, ++nextObj){	//swap elements
				if(nextObj == _vecAdr.end()){							//if iterator to next object is out of bound that mean we need to go back
					i = _vecAdr.begin();
					nextObj = i + 1;
				}
			
				if(*i > *nextObj){										//if values on iterators positions are in wrong direction => swap them and reset counter
					temp = *nextObj;
					*nextObj = *i;
					*i = temp;
					ct = 0;
				}
				else ++ct;												//increase counter
			}	
		}
	}
	return _vecAdr;	
}

//QuickSort - function will not throw exception because will sort at least as much elements as long type volume is
template<typename T>
void quickSort(const typename vector<T>::iterator &_beg, const typename vector<T>::iterator &_end, bool _dir = 0) noexcept{
	auto realEnd = (_end - 1);										//realEnd iterator is necessary because vector::.end() point address one after last element of vector
	long length = std::distance(_beg, realEnd);						//length to decide if next recursive call is necessary (1 element has not to be sort)
	
	if(length > 1){
		int pivotIndex = randomVal(length, 0);						//pivot pos & val + sorting time optimalization by use "random" index of pivot
		T pivotValue = *(_beg + pivotIndex);

		T temp = *(_beg + pivotIndex);								//swap pivot with last element of set
		*(_beg + pivotIndex) = *(realEnd);
		*(realEnd) = temp;
		
		int abstractBorder = 0;
		if(_dir){													//higher -> lower direction
			for(int i = 0; i < length; ++i){						//check whole set to the element before end (pivot is on end pos and should be not checked)
				if(*(_beg + i) > pivotValue){
					T temp = *(_beg + abstractBorder);
					*(_beg + abstractBorder) = *(_beg + i);
					*(_beg + i) = temp;
					++abstractBorder;
				}
			}
		}
		else{														//lower -> higher direction
			for(int i = 0; i < length ; ++i){						//check whole set to the element before end (pivot is on end pos and should be not checked)
				if(*(_beg + i) < pivotValue){
					T temp = *(_beg + abstractBorder);
					*(_beg + abstractBorder) = *(_beg + i);
					*(_beg + i) = temp;
					++abstractBorder;
				}
			}
		}
		
		temp = *(_beg + abstractBorder);							//swap pivot position (end) with abstract border pos
		*(_beg + abstractBorder) = *(realEnd);
		*(realEnd) = temp;			
		
		if(_dir){													//higher -> lower direction
			quickSort<T>(_beg, (_beg + abstractBorder), 1); 	 	//sort left side of pivot (abstractBorder is pos of pivot next recursive call should not include act pivot pos)
  			quickSort<T>((_beg + abstractBorder), _end, 1); 	  	//sort right side of pivot (abstractBorder is pos of pivot next recursive call should not include act pivot pos)
		}
		else{														//lower -> higher direction
			quickSort<T>(_beg, (_beg + abstractBorder));     		//sort left side of pivot (abstractBorder is pos of pivot next recursive call should not include act pivot pos)
  			quickSort<T>((_beg + abstractBorder), _end);			//sort right side of pivot (abstractBorder is pos of pivot next recursive call should not include act pivot pos)
		}
	}
}
