/*
this is same as subarray with the given sum 
we are going to cheak if there exist the array with the given reminder in the array or not
if not exist then add that rimender in the map

*/
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int cur=0;
        int count=0;
        mp[cur]++;
        for(auto it: nums){
            cur+=it;
            int mod=(cur%k);
            if(mod < 0) mod+=k;
            if(mp.find(mod) != mp.end()){
                count+=mp[mod];
            }
            mp[mod]++;
        }
        return count;
    }
};