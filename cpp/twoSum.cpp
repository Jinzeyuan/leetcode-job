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
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> nums_cp(nums);
        std::sort(nums_cp.begin(), nums_cp.end());
        for (auto iter = nums_cp.begin(),jter = nums_cp.end()-1 ;iter != jter;){
            if (*iter + *jter == target){
                vector<int> ivec(2,0);
				auto findVal = find(std::begin(nums), std::end(nums), *iter);
				auto findVal2 = find(std::begin(nums), std::end(nums), *jter);
				if (findVal2 == findVal){
					findVal2 = find(findVal+1, std::end(nums), *jter);
				}
				if ((findVal2 -findVal) >0){
					ivec[0] = findVal - nums.begin();
					ivec[1] = findVal2 - nums.begin();
				} else{
					ivec[1] = findVal - nums.begin();
					ivec[0] = findVal2 - nums.begin();
				}
                return ivec;
            } else if (*iter + *jter < target) iter++;
            else jter--;
        }
		//return nums_cp;
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
	int inputArr[] = {3,3};
	vector<int> inputVec(inputArr, inputArr + sizeof(inputArr)/sizeof(int));
	auto array = solution -> twoSum(inputVec, 6);
	printVector(inputVec);
	cout<< array[0] <<"  "<<array[1]<<endl;
	return 0;
}

