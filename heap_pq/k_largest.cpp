/*
We are going to store the k larets element in min heap then 
we will cheak if out heap size is greater then the k then we will pop the samlleset element 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            while(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};