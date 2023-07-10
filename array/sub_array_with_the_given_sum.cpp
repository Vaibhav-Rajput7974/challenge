/*
    we will use map to find the sub array
    what we are going to do is that
    we will cheak that is there a element in mp whose sum is = cursum-k
    if yes then increment the ans by that element
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]++;
        int ans=0;
        int cursum=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(mp.find(cursum-k) != mp.end()){
                ans+=mp[cursum-k];
            }
            mp[cursum]++;
        }
        return ans;
    }
};