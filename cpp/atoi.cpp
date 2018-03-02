#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

#ifndef NULL
#define NULL 0
#endif
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
using namespace std;

class Solution {
public:
	int myAtoi(string str){
		int sign = 1;
		int sum = 0;
		int i;
		for (i =0; i< str.size();i++){
			if (!isspace(str[i])) break;
		}
		if (i == str.size()) return 0;
		if (str[i]=='+') i++;
		else if (str[i]=='-'){
			sign = -1;
			i++;
		}
		if (isdigit(str[i])){
			for(; i< str.size();i++){
				if(isdigit(str[i]) && str[i]=='0') continue;
				break;
			}
			if(isdigit(str[i])){
				sum = str[i] - '0';
				sum *= sign;
				i++;
			} else return 0;
			for(; i< str.size();i++){
				if(isdigit(str[i])){
					int tmpSum = sum;
					sum *= 10;
					if(sum / 10 != tmpSum) return (sign==1)?INT_MAX:INT_MIN;
					sum += sign*(str[i]-'0');
					if ((sum^tmpSum) & 0x80000000)
						return (sign==1)?INT_MAX:INT_MIN;
				} else{
					return sum;
				}
			}
			return sum;
		} else{
			return 0;
		}
    }
};
int main(){
	auto solution = new Solution();
	//int inputArr[] = {3,3};
	//vector<int> inputVec(inputArr, inputArr + sizeof(inputArr)/sizeof(int));
	auto ret = solution -> myAtoi("  +0a32");
	//auto ret = solution->longestPalindrome("cbbd");
	cout<<ret<<endl;
	return 0;
}

