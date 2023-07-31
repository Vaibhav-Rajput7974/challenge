#include<bits/stdc++.h>
using namespace std; 
class Solution {
private:
    int n;
    vector<int> jumps = {-1, 0, 1};
    unordered_map<string, int> hashMap;
    bool solve(vector<int>& nums, int i, int prev)
    {
        if(i >= n)
        {
            return false;
        }
        if(i == n-1)
        {
            return true;
        }
        string key = to_string(i) + "_" + to_string(prev);
        if(hashMap.count(key))
        {
            return hashMap[key];
        }
        int curr = nums[i];
        bool isPossible = false;
        for(int& t: jumps)
        {
            int jump = prev + t;
            for(int j=i+1; j<n; j++)
            {
                if(curr + jump == nums[j])
                {
                    isPossible = solve(nums, j, jump);
                    if(isPossible)
                    {
                        return true;
                    }
                }
            }
        }
        return hashMap[key] = isPossible;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] > 1)
        {
            return false;
        }
        n = stones.size();
        hashMap.clear();
        return solve(stones, 1, 1);
    }
};