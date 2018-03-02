#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

/*typedef struct cacheSlice {
	int value;
	int frequency;
} cacheSlice;

typedef struct frequencyTable {
	
} fre;*/
#ifndef NULL
#define NULL 0
#endif
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ret;
		int c =0 ;
		int judge = 1;
		int digit;
		for(ListNode* node,*keep = NULL ;l1 || l2 ||c;){
			node = (ListNode*) malloc(sizeof(ListNode));
			if(judge) {
				ret = node;
				judge = 0;
			}
			if (keep) keep->next = node;
			digit = 0;
			if(l1) digit += l1->val;
			if(l2) digit += l2->val;
			digit += c;
			//digit = l1->val + l2->val +c ;
			if(digit>=10){
				c = 1;
				node-> val = digit - 10;
			} else{
				c = 0;
				node -> val = digit;
			}
			keep = node;
			if(l1) l1 = l1->next;
			if(l2) l2 = l2->next;
			node -> next = NULL;
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
	return 0;
}


