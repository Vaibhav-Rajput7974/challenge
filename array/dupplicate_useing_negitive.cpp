/*

we are going to mark the idx of that element to be vistated useing the negitive sign 
and if we have visate that idx than push that in our ans
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1] < 0){
                ans.push_back(abs(nums[i]));
            }
            nums[abs(nums[i])-1]*=-1;
        }
        return ans;
    }
};