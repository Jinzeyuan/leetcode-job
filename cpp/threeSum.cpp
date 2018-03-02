#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#ifndef NULL
#define NULL 0
#endif
using namespace std;
template <class T>
//class hashTable{
//public:
//	typedef struct hashPage{
//		T value;
//		struct hashPage* next;
//		hashPage(T value_): value(value_), next(NULL){};
//	} hashPage,*hashPoint;
//	hashTable(size_t size){
//		(hashPoint*)a = malloc(sizeof(hashPoint)* size);
//	}
//	void setKey(key,value){
//		
//	}
//private: hashPoint* a;
//};
class Solution {
public:
    string threeSum(vector<int> & nums){
		unordered_map<int,vector<int>*> a;
		unordered_map<int,vector<int>*>::iterator c;
		for(auto iter = nums.begin();iter!=nums.end();iter++){
			if((c=a.find(*iter))==a.end()){
				vector<int> *b = new vector<int>;
				b->push_back(iter-nums.begin());
				a.insert(*iter,b);
			} else{
				c->second->push_back(iter-nums.begin());
			}
		}
		return "";
    }
};
void printVector(vector<int>& arr){
	cout<< '[';
	auto iter = arr.begin();
	if(iter!= arr.end()){
		cout<< *iter;
		iter ++;
	}
	for (;iter != arr.end(); iter++){
		cout<< ',' << *iter;
	}
	cout<<']'<<std::endl;
}

int main(){
	auto solution = new Solution();
	//int inputArr[] = {3,3};
	//vector<int> inputVec(inputArr, inputArr + sizeof(inputArr)/sizeof(int));
	//auto array = solution -> intToRoman(3999);
	//printVector(inputVec);
	//cout<< array<<endl;
	return 0;
}

