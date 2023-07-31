/*
min sum of element in the path from top to bottom 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int> > &grid,vector<vector<int> > &dp){
        if(i == n && j == m){
            return grid[i][j];
        }
        if(i>n || j>m){
            return INT_MAX;
        }
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j]=min(helper(i+1,j,n,m,grid,dp),helper(i,j+1,n,m,grid,dp))+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int> > dp(grid.size(),vector<int> (grid[0].size(),-1));
        return helper(0,0,grid.size()-1,grid[0].size()-1,grid,dp);
    }
};