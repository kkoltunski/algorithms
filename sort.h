#include "Trees.h"

extern int rangedRandomValue(int _upRange, int _botRange);

template<typename T>
void swap(T& _source, T& _destination){
	T storage = _destination;
	_destination = _source;
	_source = storage;
}

//Bubble sort - argument passed as initializer list to object
template<typename T>
vector<T> bubbleSort(const std::initializer_list<T> &_inputL, bool _dir = 0) throw(std::out_of_range){
	vector<T> tabVec {_inputL};												//result vector
	auto secondObj = (_dir ? (tabVec.end() - 2) : (tabVec.begin() + 1));	//next object depend on direction
	unsigned short correctComparissionCt = 0;								//value to count "no change" pairs

	if(std::numeric_limits<unsigned short>::max() < tabVec.size())			//if too many elements in initializer list then throw exception
		throw(std::out_of_range("counter val. is to low"));
							
	if(tabVec.size() > 1){													//one element has not to be sort
		if(_dir){															//higher -> lower direction
			for(auto firstObj = (tabVec.end() - 1); (correctComparissionCt <= (tabVec.size() - 1)); --firstObj, --secondObj){	//swap elements
				if(secondObj == (tabVec.begin() - 1)){						//if iterator to next object is out of bound that mean we need to go back
					firstObj = tabVec.end();
					secondObj = firstObj - 1;
				}
			
				if(*firstObj > *secondObj){									//if values on iterators positions are in wrong direction => swap them and reset counter
					swap<T>(*secondObj, *firstObj);
					correctComparissionCt = 0;
				}
				else ++correctComparissionCt;								//increase counter	
			}
		}
		else{																//lowe -> higher direction
			for(auto firstObj = tabVec.begin(); (correctComparissionCt <= (tabVec.size() - 1)); ++firstObj, ++secondObj){	//swap elements
				if(secondObj == tabVec.end()){								//if iterator to next object is out of bound that mean we need to go back
					firstObj = tabVec.begin();
					secondObj = firstObj + 1;
				}
			
				if(*firstObj > *secondObj){									//if values on iterators positions are in wrong direction => swap them and reset counter
					swap<T>(*secondObj, *firstObj);
					correctComparissionCt = 0;
				}
				else ++correctComparissionCt;								//increase counter
			}	
		}
	}
	return tabVec;
}

//Bubble sort - argument passed as address to object - have to be non-const bc will be operated on orginal vector
template<typename T>
vector<T>& bubbleSort(vector<T> &_inVec, bool _dir = 0) throw(std::out_of_range){
	auto secondObj = (_dir ? (_inVec.end() - 2) : (_inVec.begin() + 1));	//next object depend on direction
	unsigned short correctComparissionCt = 0;								//value to count "no change" pairs

	if(std::numeric_limits<unsigned short>::max() < _inVec.size())			//if too many elements in initializer list then throw exception
		throw(std::out_of_range("counter possible value is to low"));					
	
	if(_inVec.size() > 1){													//one element has nt to be sort
		if(_dir){															//higher -> lower direction
			for(auto firstObj = (_inVec.end() - 1); (correctComparissionCt <= (_inVec.size() - 1)); --firstObj, --secondObj){	//swap elements
				if(secondObj == (_inVec.begin() - 1)){						//if iterator to next object is out of bound that mean we need to go back
					firstObj = _inVec.end();
					secondObj = firstObj - 1;
				}
				
				if(*firstObj > *secondObj){									//if values on iterators positions are in wrong direction => swap them and reset counter
					swap<T>(*secondObj, *firstObj);
					correctComparissionCt = 0;
				}
				else ++correctComparissionCt;								//increase counter	
			}
		}
		else{																//lowe -> higher direction
			for(auto firstObj = _inVec.begin(); (correctComparissionCt <= (_inVec.size() - 1)); ++firstObj, ++secondObj){	//swap elements
				if(secondObj == _inVec.end()){								//if iterator to next object is out of bound that mean we need to go back
					firstObj = _inVec.begin();
					secondObj = firstObj + 1;
				}
			
				if(*firstObj > *secondObj){									//if values on iterators positions are in wrong direction => swap them and reset counter
					swap<T>(*secondObj, *firstObj);
					correctComparissionCt = 0;
				}
				else ++correctComparissionCt;								//increase counter
			}	
		}
	}
	return _inVec;	
}

//QuickSort - function will not throw exception because will sort at least as much elements as long type volume is
template<typename T>
void quickSort(const typename vector<T>::iterator &_beg, const typename vector<T>::iterator &_end, bool _dir = 0) noexcept{
	auto realEnd = (_end - 1);												//realEnd iterator is necessary because vector::.end() point address one after last element of vector
	long length = std::distance(_beg, realEnd);								//length to decide if next recursive call is necessary (1 element has not to be sort)
	
	if(length > 1){
		int pivotIndex = rangedRandomValue(length, 0);						//pivot pos & val + sorting time optimalization by use "random" index of pivot
		T pivotValue = *(_beg + pivotIndex);
		
		swap<T>(*(_beg + pivotIndex), *realEnd);							//swap pivot with last element of set
		
		int abstractBorder = 0;
		if(_dir){															//higher -> lower direction
			for(int i = 0; i < length; ++i){								//check whole set to the element before end (pivot is on end pos and should be not checked)
				if(*(_beg + i) > pivotValue){
					swap<T>(*(_beg + abstractBorder), *(_beg + i));
					++abstractBorder;
				}
			}
		}
		else{																//lower -> higher direction
			for(int i = 0; i < length ; ++i){								//check whole set to the element before end (pivot is on end pos and should be not checked)
				if(*(_beg + i) < pivotValue){
					swap<T>(*(_beg + abstractBorder), *(_beg + i));
					++abstractBorder;
				}
			}
		}
		
		swap<T>(*(_beg + abstractBorder), *realEnd);						//swap pivot position (end) with abstract border pos
		
		if(_dir){															//higher -> lower direction
			quickSort<T>(_beg, (_beg + abstractBorder), 1);					//sort left side of pivot (abstractBorder is pos of pivot next recursive call should not include act pivot pos)
  			quickSort<T>((_beg + abstractBorder), _end, 1);					//sort right side of pivot (abstractBorder is pos of pivot next recursive call should not include act pivot pos)
		}
		else{																//lower -> higher direction
			quickSort<T>(_beg, (_beg + abstractBorder));					//sort left side of pivot (abstractBorder is pos of pivot next recursive call should not include act pivot pos)
  			quickSort<T>((_beg + abstractBorder), _end);					//sort right side of pivot (abstractBorder is pos of pivot next recursive call should not include act pivot pos)
		}
	}
}
