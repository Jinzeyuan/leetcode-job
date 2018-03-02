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
    string convert(string s, int numRows) {
		if (numRows <=1 ) return s;
		int maxLine = s.size()/(numRows-1)+1;
        char a[numRows][maxLine]={{0}};
		int state =0;
		int i,j=0,t=0;
		a[0][0] = s[0];
		for (i = 1;i<s.size();i++){
			if (!state){
				if(j == numRows -1){
					state = 1;
					j = numRows -2;
					if(j ==0) {i--; continue;}
					t = t+1;
				} else{
					j = j+1;
				}
			} else{
				if(j == 1){
					state = 0;
					j = 0;
					t = t+1;
				} else if(j == 0){
					state = 0;
					t = t+1;
				} else {
					j = j-1;
				}
			}
			a[j][t] = s[i];
		}
		string ret(s);
		int iter=0;
		for (int n = 0; n< numRows;n ++){
			for(int m = 0; m< maxLine; m++){
				if(a[n][m]) ret[iter++] = a[n][m];
			}
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
	string input("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.");
	auto ret = solution -> convert(input,3);
	//auto ret = solution->longestPalindrome("cbbd");
	cout<<ret<<endl;
	return 0;
}

