/*
dial the n length number useing dailer of phone 

 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dx[8]={-2,-2,-1,1,2,2,-1,1};
int dy[8]={-1,1,-2,-2,-1,1,2,2};
int mod=1000000007;
long helper(int n,int x,int y,vector<vector<int> > &mat,vector<vector<vector<long> > > &dp){
    if(n == 1)return 1;
    if(dp[n][x][y] != -1)return dp[n][x][y];
    long ans=0;
    for(int i=0;i<8;i++){
        int row=x+dx[i];
        int col=y+dy[i];
        if(row>=0 && row<4 && col >=0 && col <3 && mat[row][col] != 11){
            ans=(ans+helper(n-1,row,col,mat,dp))%mod;
        }
    }
    return dp[n][x][y]=ans;

}
    int knightDialer(int n) {
        long ans=0;
        vector<vector<int> >  mat={
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {11,0,11},
        };
        vector<vector<vector<long> > > dp(n+1,vector<vector<long> > (4,vector<long> (3,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(mat[i][j] != 11){
                    ans=(ans+helper(n,i,j,mat,dp))%mod;
                }
            }
        }
        return (int)ans;

    }
};