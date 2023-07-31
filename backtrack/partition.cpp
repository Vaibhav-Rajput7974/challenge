/*
    divide array into equall parts
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int helper(int idx,int N,int arr[],int cursum,vector<vector<int> > &dp){
        if(idx == N){
            if(cursum == 0)return 1;
            return 0;
        }
        if(dp[idx][cursum] != -1)return dp[idx][cursum];
        
        return dp[idx][cursum]=helper(idx+1,N,arr,cursum-arr[idx],dp) || helper(idx+1,N,arr,cursum,dp);
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum %2 == 1)return 0;
        vector<vector<int> > dp(N+1,vector<int> (sum+1,-1));
        return helper(0,N,arr,sum/2,dp);
    }
};