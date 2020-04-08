#ifndef TREES_H
#define TREES_H

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

template<typename T>
class BST;
template<typename T>
class node;

template<typename T>
std::ostream& operator<<(std::ostream &_outStream, node<T>& _inNode){
	if(_inNode.pToFather == nullptr) _outStream << "\nNode is root node" << endl;
	else  _outStream << "\nNode is not root node. It's father is node " << _inNode.pToFather << endl;
	
	if(_inNode.pToLeftSon == nullptr) _outStream << "Node has not left son" << endl;
	else _outStream << "Node left son is node " << _inNode.pToLeftSon << endl;
	
	if(_inNode.pToRightSon == nullptr) _outStream << "Node has not right son" << endl;
	else _outStream << "Node right son is node " << _inNode.pToRightSon << endl;
	
	_outStream << "Node data = " << _inNode.data << endl;
	return _outStream;
}

///////////////////////////////////////NODE MANAGEMENT////////////////////////////////////
/*node is single part of tree and have to have informations about father 
(node where this node come from) and this node sons (up to 2 sons)*/
template<typename T>
class node{													
	private:
		using tP = node*;
		
		node *pToFather;
		node *pToLeftSon;
		node *pToRightSon;
		T data;
	
		node<T>()	: pToFather(nullptr), pToLeftSon{nullptr}, pToRightSon{nullptr}, data{0}
		{
		};
		node<T>(tP _ptf, tP _ptls, tP _ptrs, T _d) :   pToFather(_ptf), pToLeftSon{_ptls}, pToRightSon{_ptrs},
												   data{_d}
		{
		};
	
		node<T>& swapNodes(node<T> &_in);							//swap function - for operation at trees nodes (it could be operator=, functionality is similar but i decide to do it by function)
		
	friend class BST<T>;
	friend std::ostream& operator<<<>(std::ostream &_outStream, node<T>& _inNode);
};

//template<typename T>
//node<T>::~node<T>(){
//}

template<typename T>
node<T>& node<T>::swapNodes(node<T> &_in){
	if(this != &_in){
		auto *tempNode = new node<T>(nullptr, nullptr, nullptr, 0);						
		
		tempNode->pToFather = _in.pToFather;						//nodes handshake
		tempNode->pToLeftSon = _in.pToLeftSon; 
		tempNode->pToRightSon = _in.pToRightSon;
		tempNode->data = _in.data;
		
		_in.pToFather = pToFather;
		_in.pToLeftSon = pToLeftSon; 
		_in.pToRightSon = pToRightSon;
		_in.data = data;
		
		pToFather = tempNode->pToFather;
		pToLeftSon = tempNode->pToLeftSon; 
		pToRightSon = tempNode->pToRightSon;
		data = tempNode->data;
		
		delete tempNode;
 	}
 	
 	return *this;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////BST MANAGEMENT//////////////////////////////////
/*there are few constatnt expression which are always true and im using it in code bellow:
node father index = (1 - _nodeIndex) / 2);
left father son = 2 * _fatherNodeIndex + 1; 
right father son = 2 * _fatherNodeIndex + 2
based on above expressions we can easliy move through array or vector.*/
template<typename T>
class BST{
	private:
	public:
		BST<T>(const vector<T> &_inVec);
		virtual ~BST<T>();
		
		//virtual T& push(T _inVal);								//this function will be used for add node to existed tree	
		void showCreatedNodes();									//help function
		
	protected:														//i except that functions attached to this section will be used in derived class
		node<T> *rootAdr;											//because of balancing operation this value is not constatn - it will be changing while rotations	
		vector<node<T>*> createdNodes;
		
		virtual bool findDuplicate(T _inVal);						//f. to searching for duplicate datas (duplicates should not be added to tree again)
		virtual node<T>& rotation(node<T> *_pivotAdr);				//f. to recognize which kind of rotation is able to be done
		virtual void balancing();									//f. to balance nodes (after this call nodes are sorted) - second part of DSW algorithm
		
};

template<typename T>
BST<T>::BST(const vector<T> &_inVec){
	if(!_inVec.empty()){
		auto *rootNode = new node<T>;
		rootAdr = rootNode;											//first initialization of pToRoot is necessary to next operation
		
		rootNode->pToFather = nullptr;								//creating root node (it is always index 0)
		rootNode->data = _inVec[0];									//which data is equal first element of delivered vector
		createdNodes.push_back(rootNode);							//root node on tree vector [0] index
		
		for(int k = 1; k < _inVec.size(); ++k){						//DSW first step - create line list in right path of tree					
			if(findDuplicate(_inVec[k])) continue;					//avoid doubled elements value
			
			auto *tempNode = new node<T>();
			node<T> *pToNode = rootAdr;								//route should be checked always from root node
			int newIndex = 0;
			
			while(!newIndex){										//find index of new node		
				if(_inVec[k] > pToNode->data){						//if value is larger than root go to right son
					if(pToNode->pToRightSon == nullptr)	newIndex = 2;//if father has not right son then index is found	
					else pToNode = pToNode->pToRightSon;			//if father has right son then next father to check is this son
				}
				else{												//if value is smaller than root go to left son
					if(pToNode->pToLeftSon == nullptr) newIndex = 1;//if father has not left son then position is found
					else pToNode = pToNode->pToLeftSon;				//if father has left son then next father to check is this son
				}
			}		
			
			tempNode->pToFather = pToNode;							//make connection between son and dad
			tempNode->data = _inVec[k];
			(!(newIndex % 2) ? pToNode->pToRightSon : pToNode->pToLeftSon ) = tempNode;
			createdNodes.push_back(tempNode);
		
			if(newIndex % 2) rotation(tempNode);					//if new node is added on root left side then rotate this (purpose - when loop will be finished we will have line list ready for step II of DSW)
		}
//		for(int i = 0; i < createdNodes.size(); ++i){				//nodes diagnostic to check results 
//			cout << *createdNodes[i];
//		}		
		balancing();												//DSW second step - create balanced tree
		
//		for(int i = 0; i < createdNodes.size(); ++i){				//nodes diagnostic to check results 
//			cout << *createdNodes[i];
//		}
	}	
}

template<typename T>
BST<T>::~BST<T>(){
	for(int i = 0; i < createdNodes.size(); ++i)	delete createdNodes[i];
}

template<typename T>
bool BST<T>::findDuplicate(T _inVal){										//simple function to define if value has duplicate in vector
	bool duplicateFound {false};
	
	for(int i = 0; i < createdNodes.size(); ++i){					//just check given vector 
		duplicateFound = (_inVal == createdNodes[i]->data ? true : false);
		if(duplicateFound) break;									//if duplicate is found - it is not necessary to continue checking
	}
	
	return duplicateFound;
}

template<typename T>
node<T>& BST<T>::rotation(node<T> *_pivotAdr){	
	if(_pivotAdr != rootAdr){										//check if pivot is not actual root - only sons are able to be rotated
		node<T> *node<T>::*pToSon;
		node<T> *fatherAdr = _pivotAdr->pToFather;
		node<T> *grandpaAdr = fatherAdr->pToFather;
				
		if(fatherAdr->pToLeftSon == _pivotAdr) pToSon = &node<T>::pToLeftSon;
		else pToSon = &node<T>::pToRightSon;
																	//Right rot -> pToSon = pToLeftSon, left rot -> pToSon = pToRightSon
		fatherAdr->*pToSon = (pToSon == &node<T>::pToLeftSon ? _pivotAdr->pToRightSon : _pivotAdr->pToLeftSon);
		fatherAdr->pToFather = _pivotAdr;
		
		if(grandpaAdr != nullptr){									//if pivot's father has father then it have to be adjusted
			_pivotAdr->pToFather = grandpaAdr;
			
			if(grandpaAdr->pToRightSon == fatherAdr) grandpaAdr->pToRightSon = _pivotAdr;	//check which son address have to be changed - right or...		
			else grandpaAdr->pToLeftSon = _pivotAdr;				//...left		
		}
		else{														//pivot become root node
			_pivotAdr->pToFather = nullptr;
			rootAdr = _pivotAdr;
		} 
																	//pivot is father now so "sons" have to be adjusted
		(pToSon == &node<T>::pToLeftSon ? _pivotAdr->pToRightSon : _pivotAdr->pToLeftSon) = fatherAdr;
	}
	return *_pivotAdr;
}

template<typename T>
void BST<T>::balancing(){											//!!!!maybe will be necessary to add checking left part and rotation operations
	if(rootAdr->pToRightSon != nullptr){							//to start balancing right path should be prepared already							
		auto pivot = rootAdr->pToRightSon;
		node<T> *temp = rootAdr->pToRightSon;						//used as node counter											
		int ct {0};													//counter to calculate how many rotations are need in first balancing cycle
		
		for(;temp != nullptr; ++ct) temp = temp->pToRightSon;		//calculate how much nodes are in path
		
		while(ct != 0){
			for(int i = 0; i < (ct / 2); ++i){						//first cycle - rotate every second node 
				rotation(pivot);
				for(int x = 0; x < 2; ++x, pivot = pivot->pToRightSon){	//move to the grandson
					if(pivot->pToRightSon == nullptr) break;
				}
			}
			ct >>= 1;												//at the end of cyckle prepare data for next cycle - divide count of rotation
			pivot = rootAdr->pToRightSon;							//set pivot position
		}
	}
}

template<typename T>
void BST<T>::showCreatedNodes(){
	for(int i = 0; i < createdNodes.size(); ++i){
		cout << "BTS.createdNodes[" << i << "].data = ";
		if(createdNodes[i])	cout << createdNodes[i]->data;			//if address is different than zero then index is ocupied by node and has data so it could be shown
		else cout << 0;
		cout << ", address = " << createdNodes[i] << endl;
	}
}

#endif
