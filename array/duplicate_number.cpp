/*
we have used the concopt of flod washal algorithm in this proble 
beacuse repiting element are going to for the cycle in array
so we are going to use ther value and index for the traversal

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int totoise=nums[0];
        int rab=nums[0];
        do{
            totoise=nums[nums[totoise]];
            rab=nums[rab];
        }while(totoise != rab);
         totoise=nums[0];
        while(totoise != rab){
            totoise=nums[totoise];
            rab=nums[rab];
        }
        return rab; 
    }
};