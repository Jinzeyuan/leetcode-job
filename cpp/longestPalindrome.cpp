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
	int checkValid(string const & s, int left, int right){
		if(left<0 || right>= s.size() || s[left] != s[right]){
			return left+1;
		}
		return checkValid(s,left-1, right+1);
	}
    string longestPalindrome(string s) {
		int i = 0;
		int max = 1;
		int maxLeft = 0;
		int maxRight = 0;
		for(i=0;i< s.size();i++){
			int begin = checkValid(s ,i,i+1);
			//if (begin>i) continue;
			if ((i-begin+1)*2 > max){
				maxLeft = begin;
				maxRight = 2*i-begin +1;
				max = maxRight - maxLeft +1;
			}
		}
		for(i=0;i< s.size();i++){
			int begin = checkValid(s ,i,i+2);
			//if (begin>i) continue;
			if ((i-begin+1)*2 +1 > max){
				maxLeft = begin;
				maxRight = 2*i-begin +2;
				max = maxRight - maxLeft +1;
			}
		}
		string ret(max,0);
		for (i = 0;i<max;i++){
			ret[i] = s[i+maxLeft];
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
	//auto array = solution -> twoSum(inputVec, 6);
	auto ret = solution->longestPalindrome("cbbd");
	cout<<ret<<endl;
	return 0;
}

