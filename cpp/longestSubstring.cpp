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
	int checkValid(string s, int iter, int begin){
		for(int i=iter-1; i>=begin; i--){
			if(s[iter] == s[i])
				return i+1;
		}
		return 0;
	}
    int lengthOfLongestSubstring(string s) {
		int i = 0;
		int commonBegin = 0;
		int longestBegin = 0;
		int longestEnd = 0;
		if (s.size()==0) return 0;
		for (i=1; i<s.size(); i++){
			if (int begin = checkValid(s, i, commonBegin)){
				if (i-1 - commonBegin > longestEnd - longestBegin){
					longestBegin = commonBegin;
					longestEnd = i-1;
				}
				commonBegin = begin;
			}
		}
		if (i-1 -commonBegin > longestEnd - longestBegin){
			return i-commonBegin;
		}
		return longestEnd - longestBegin+1;
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
	//auto array = solution -> twoSum(inputVec, 6);
	int length = solution->lengthOfLongestSubstring("au");
	cout<<length<<endl;
	return 0;
}



