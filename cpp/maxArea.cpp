#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

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

class Solution {
public:
	//int maxArea(vector<int>& height, int i,int j){
	//    int size = j-i;
	//	if (size==0) return 0;
	//	if (maxTable[i*height.size()+j]) return maxTable[i*height.size()+j];
	//	int ret = max(max(min(height[i],height[j])*size,maxArea(height,i+1,j)),maxArea(height,i,j-1));
	//	maxTable[i*height.size()+j] = ret;
	//	return ret;

	//}

	vector<int>::iterator maxVal(vector<int> & height){
		auto max = height.begin();
		for(auto iter = height.begin()+1;iter!=height.end();iter++){
			if (*iter>*max){
				max = iter;
			}
		}
		return max;
	}
	template<class T>
	vector<int> findIncreasingVec(T begin, T end){
		int max = *begin;
		vector<int> ret;
		ret.push_back(0);
		for(auto iter = begin+1; iter != end+1; iter++){
			if (*iter>max){
				ret.push_back(iter-begin);
				max = *iter;
			}
		}
		return ret;
	}
    int maxArea(vector<int>& height) {
	    //int size = height.size();
		//maxTable = (int*)malloc(sizeof(int)*size*size);
		//memset(maxTable,0,sizeof(int)*size*size);
		//return maxArea(height,0,size-1);
		auto max = maxVal(height);
		auto left = findIncreasingVec(height.begin(), max);
		auto right = findIncreasingVec(height.rbegin(), (vector<int>::reverse_iterator) max);
		int maxVal = 0;
		for(auto i = left.begin(); i!= left.end();i++){
			for(auto j = right.begin(); j!= right.end();j++){
				int s = min(height[*i], height[height.size()-*j-1])* (height.size()-*i-*j-1);
				if (s > maxVal)
					maxVal = s;
			}
		}
		return maxVal;
	}
private:
	int *maxTable;
};
int main(){
	auto solution = new Solution();
	int inputArr[] = {1,2};
	vector<int> inputVec(inputArr, inputArr + sizeof(inputArr)/sizeof(int));
	auto array = solution -> maxArea(inputVec);
	//printVector(inputVec);
	cout<< array <<endl;
	return 0;
}
