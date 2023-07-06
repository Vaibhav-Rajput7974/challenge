/*
in a move we can increase a n-1 element by one 
which is same as decresing the one element by one value 
so  min move requare is to make all element equal is elemnt - min element of array

    ans += (current element - min of array);
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto it:nums){
            mini=min(mini,it);
        }
        int ans=0;
        for(auto it: nums){
            ans+=(it-mini);
        }
        return ans;
    }
};
