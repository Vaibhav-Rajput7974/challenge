/*


1673. Find the Most Competitive Subsequence
Medium
1.8K
86
Companies
Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

 

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
Example 2:

Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length
*/

/*
    Approch 1
    We will are useing sliding window technique to find 
    what we are going to do is we will find the min element in the current window whose size is array size - k 
    then we will add that element to the our ans and all the element whose idx is smaller then that element are pop out  and our new element will pe push 
    now we will find the min element in this window 
    and we will repite this process till array size 

    Approch 2 
    we can also use stack 
    we will create a increasing order stack 
    and will also keep the count of element to be removed from the stack 
    so we have to remove array size - k element from the stack to find the right ans 
    for that we will keep the track of element remove from stack to mantane the incresing order 
    if we have traverse all our array and some element are left to be romove to get ans 
    so we will remove all those element from the top of the stack and return the final stack 


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> >  > pq;
        int len=nums.size()-k;
        for(int i=0;i<=len;i++){
            pq.push({nums[i],i});
        }
        vector<int> res;
        res.push_back(pq.top().first);
        int minIdx=pq.top().second;
        pq.pop();
        for(int i=len+1;i<nums.size();i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<minIdx){
                pq.pop();
            }
            res.push_back(pq.top().first);
            minIdx=pq.top().second;
            pq.pop();
        }
        return res;
    }
};