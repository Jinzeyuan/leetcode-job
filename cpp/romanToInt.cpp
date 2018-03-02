#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#ifndef NULL
#define NULL 0
#endif
using namespace std;
class Solution {
public:
	int c[128];
    int romanToInt(string s){
		int ret = 0;
		c['I'] = 1;
		c['X'] = 10;
		c['C'] = 100;
		c['M'] = 1000;
		c['V'] = 5;
		c['L'] = 50;
		c['D'] = 500;
		for (auto iter = s.begin(); iter!= s.end(); iter++){
			if ((iter+1 != s.end())&& c[*iter] < c[*(iter+1)]) ret-= c[*iter];
			else ret += c[*iter];
			//cout<< ret<< endl;
		}
		return ret;
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
	auto array = solution -> romanToInt("MMMCMXCIX");
	//printVector(inputVec);
	cout<< array<<endl;
	return 0;
}

