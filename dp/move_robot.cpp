/*
move robot from one end to other 

 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int count(int i,int j,int n,int m,vector<vector<int> > &dp)
{
    if(i==n-1 && j== m-1)
    {
        return 1;
    }
    if(i>=n || j>=m)
    {
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = count(i+1,j,n,m,dp)+count(i,j+1,n,m,dp);
    
}
    int uniquePaths(int m, int n) {
        vector< vector <int> > dp(n+1,vector<int> (m+1,-1));
        return count(0,0,n,m,dp);
    }
};