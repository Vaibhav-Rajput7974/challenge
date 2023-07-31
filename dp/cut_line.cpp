/*
cut line i segament of size x y z 

 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    //Function to find the maximum number of cuts.
    int helper(int n,int x,int y,int z,vector<int> &dp){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        
        if(dp[n] != -1) return dp[n];
        int first=helper(n-x,x,y,z,dp)+1;
        int second=helper(n-y,x,y,z,dp)+1;
        int third=helper(n-z,x,y,z,dp)+1;
        int ans=max(first,max(second,third));
        return dp[n]=ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1);
        int ans=helper(n,x,y,z,dp);
        return ans<0 ? 0 : ans;
    }
};