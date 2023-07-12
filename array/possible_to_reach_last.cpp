#include<bits/stdc++.h>
using namespace std;

                //GREEDY
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //it shows at max what index can I reach.
        //initially I can only reach index 0, hence reach = 0
        int reach = 0; 
    
        for(int idx = 0; idx < nums.size(); idx++) {
            //at every index I'll check if my reach was atleast able to 
            //reach that particular index.
            
            //reach >= idx -> great, carry on. Otherwise, 
            if(reach < idx) return false;
            
            //now as you can reach this index, it's time to update your reach
            //as at every index, you're getting a new jump length.
            reach = max(reach, idx + nums[idx]);
        }
        
        //this means that you reached till the end of the array, wohooo!! 
        return true;
        
    }
};
            // Dynamic Programming
class Solution {
public:
bool cheak(int st,vector<int> &nums,vector<int> &dp)
{
    if(st >= nums.size() -1)
    {
        return true;
    }

    if(dp[st] != -1)
       return dp[st];

    if(nums[st] == 0)
        return false;

    int count=nums[st];
    int i=1;
    while( i<=count && st+i < nums.size())
    {
        if(cheak(i+st,nums,dp))
        {
            return dp[st]= true;
           // break;
        }
        i++;
    }
    return dp[st]=false;
}
    bool canJump(vector<int>& nums) {
        int start=0;
        vector<int> dp(nums.size(),-1);
        return cheak(0,nums,dp);
    }
};