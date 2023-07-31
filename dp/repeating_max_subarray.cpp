/*
cheak the first characeter in both array then if it is equal then calculate the length from that point

 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int helper(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int> > &dp){
        if(i == nums1.size() || j == nums2.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(nums1[i] == nums2[j])return dp[i][j]=1+helper(i+1,j+1,nums1,nums2,dp);
        return dp[i][j]=0;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        vector<vector<int> > dp(nums1.size(),vector<int> (nums2.size(),-1));
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    ans=max(ans,helper(i,j,nums1,nums2,dp));
                }
            }
        }
        return ans;
    }
};