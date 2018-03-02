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
	int bits(int x){
		return x?bits(x/10)+1:0;
	}
	int rev(int x, int bit){
		if (x<10) return x;
		int end = x%10;
		for (int i =1;i<bit;i++){
			int tmpEnd = end;
			end*=10;
			if (tmpEnd != end/10) return 0;
		}
		int calcVal = rev(x/10,bit-1)+end;
		if (calcVal<end) return 0;
		else return calcVal;
	}
	int reverse(int x){
		int sign = x<0 ? -1 :1;
		if (x == -2147483648) return 0;
		x*=sign;
		int bit = bits(x);
		int ret = sign*rev(x, bit);
		return ret;
    }
};
int main(){
	auto solution = new Solution();
	//int inputArr[] = {3,3};
	//vector<int> inputVec(inputArr, inputArr + sizeof(inputArr)/sizeof(int));
	auto ret = solution -> reverse(-123);
	//auto ret = solution->longestPalindrome("cbbd");
	cout<<ret<<endl;
	return 0;
}
