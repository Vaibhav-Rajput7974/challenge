#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int pre,int idx,vector<int> &nums,vector<vector<int> >&dp){
        if(idx == nums.size())return 0;
        if(dp[pre+1][idx]!=-1)return dp[pre+1][idx];
        int take=0;
        if( pre == -1 ||nums[pre]<nums[idx])
            take=helper(idx,idx+1,nums,dp)+1;
        int nottake=helper(pre,idx+1,nums,dp);
        return dp[pre+1][idx]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int> > dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        return helper(-1,0,nums,dp);
    }
};