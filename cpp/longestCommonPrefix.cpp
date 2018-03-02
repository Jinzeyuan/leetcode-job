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
    string longestCommonPrefix(vector<string> & strs){
		int i,j;
		if (strs.size()==0) return "";
		for(i=0;1;i++){
			if (strs[0].size() ==i) return strs[0];
			char a = strs[0][i];
			for(j = 1; j< strs.size();j++){
				if (strs[0].size() ==i) return strs[j];
				if (strs[j][i] != strs[j][i]) goto CHECK;
			}
		}
CHECK:
		i = i;
		string s(i,0);
		for (int t = 0; t<i;t ++){
			s[t] = strs[0][t];
		}
		return s;
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
