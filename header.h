#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <initializer_list>
#include "recursion.h"		//header with recursion functions definitions
#include "sort.h"			//header with sorting functions and data structures
#include "ThueMorsWord.h"	//header with Thue Mors word algorithm

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//Generate "random" value in range - maybe better if function will be in "sort.h" ?
int randomVal(int _upRange, int _botRange = 0){
	return _botRange + int((_upRange-_botRange+1) * rand()/(RAND_MAX+1.0));	
}
