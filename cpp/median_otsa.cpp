#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3(nums1.size() + nums2.size());
        auto i = nums1.begin();
        auto j = nums2.begin();
        auto z = nums3.begin();
        while(i != nums1.end() && j != nums2.end()){
            if(*i >= *j){
                *z = *j;
                j++;
                z++;
            } else{
                *z = *i;
                i++;
                z++;
            }
        }
        if( i == nums1.end() ){
            while ( j != nums2.end() ){
                *z = *j;
                j++;
            }
        } else{
            while ( i != nums1.end() ){
                *z = *i;
                i++;
            }
        }
		int k = nums1.size() + nums2.size();
		double result;
		if(k%2){
			result = nums3[k/2];
		} else{
			result = nums3[k/2] + nums3[k/2-1];
			result/=2;
		}
        
		return result;
    }
};
