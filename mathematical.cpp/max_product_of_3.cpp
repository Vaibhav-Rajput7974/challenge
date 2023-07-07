/*
    product of 3 greatest number is max 
    or product of two smallest negitive number with the greatest number is greatest
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        ans=max(ans,(nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]));
        ans=max(ans,nums[nums.size()-1]*(nums[0]*nums[1]));
        return ans;
    }
};