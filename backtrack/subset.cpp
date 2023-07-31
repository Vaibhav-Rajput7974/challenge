/*
    create subset of array 
    
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int> >res;
    void helper(int idx,vector<int> &nums,vector<int> &ans){
        res.push_back(ans);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i] == nums[i-1])continue;
            ans.push_back(nums[i]);
            helper(i+1,nums,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        helper(0,nums,ans);
        //vector<vector<int> > res;
        return res;
    }
};