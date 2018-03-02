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
/*	bool checkPalindrome(int x, int state, int c){
		if (x==0) return false;
		if (!(x/10)){
			return (x==c+state);
		}
		if((c==x%10-state)&&(c==x%100/10)) return checkPalindrome(x/100, state,c);
		else return false;
	}
	bool checkSame(int x, int c){
		if (!x) return true;
		return x%10==c ? checkSame(x/10,c) : false;
	}
*/
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
	bool isPalindrome(int x) {
		int state = 0;
        if (x<0) return false;
		if (!(x/10)) return true;
		int pairX = reverse(x);
		return pairX == x;
	}
};
int main(){
	auto solution = new Solution();
	//int inputArr[] = {3,3};
	//vector<int> inputVec(inputArr, inputArr + sizeof(inputArr)/sizeof(int));
	auto ret = solution -> isPalindrome(12);
	//auto ret = solution->longestPalindrome("cbbd");
	cout<<ret<<endl;
	return 0;
}


