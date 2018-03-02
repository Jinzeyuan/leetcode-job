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
	int a[4] = {'I', 'X', 'C', 'M'};
	int b[3] = {'V', 'L', 'D'};
	string convertBit(int bit, int pos){
		string s = "";
		switch (bit){
			case 0 :return string(""); break;
			case 1 : case 2: case 3:
				for(int i = 0; i<bit;i++){
					s.push_back(a[pos]);
				}
				return s;
				break;
			case 4:
				s.push_back(a[pos]);
				s.push_back(b[pos]);
				return s;
				break;
			case 5:
				s.push_back(b[pos]);
				return s;
				break;
			case 6: case 7: case 8:
				s.push_back(b[pos]);
				for(int i = 0; i<bit-5;i++){
					s.push_back(a[pos]);
				}
				return s;
				break;
			case 9:
				s.push_back(a[pos]);
				s.push_back(a[pos+1]);
				return s;
				break;
		}
	}
    string intToRoman(int num){
		string ret;
		for (int i =0; num!=0; num/=10, i++){
			ret = convertBit(num%10,i) + ret;
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
	auto array = solution -> intToRoman(3999);
	//printVector(inputVec);
	cout<< array<<endl;
	return 0;
}

