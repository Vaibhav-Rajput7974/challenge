/*
move robot from one end to other 

 */
#include<bits/stdc++.h>
using namespace std; 
int mincostree(int freq[], int i, int r, vector<vector<int>>& dp) {
        
        if(i>r) {
            return 0;
        }
        
        if(dp[i][r]!=-1) {
            return dp[i][r];
        }
        
        int ans=INT_MAX;
        
        for(int j=i; j<=r; ++j) {
            int left=mincostree(freq,i,j-1,dp);
            int right=mincostree(freq,j+1,r,dp);
            ans=min(ans,left+right);
        }
        for(int j=i; j<=r; ++j) {
                ans+=freq[j];
            }
        return dp[i][r]=ans;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
       vector<vector<int>> dp(n,vector<int>(n,-1));
       return mincostree(freq,0,n-1,dp);
    }