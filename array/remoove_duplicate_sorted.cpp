#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        int sz=nums.size();
        for(int i=0;i<sz;i++)
        {
            mp[nums[i]]++;
        }
        map<int,int> ::iterator it;
        int next=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            nums[next]=it->first;
            next++;
        }
        //int ans=mp.size();
        return next;
    }
};