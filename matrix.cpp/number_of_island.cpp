/*
    It is same as find number of connected component in the graph
    so we are goin to use simpl BSF technique for the question 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dx[8]={1,1,1,0,-1,-1,-1,0};
    int dy[8]={1,0,-1,-1,-1,0,1,1};
    void bfs(int row,int col,vector<vector<char> > &grid,vector<vector<int> > &vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int> > q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<q.size();i++){
                auto node=q.front();
                q.pop();
                for(int j=0;j<8;j++){
                    int currow=node.first+dx[j];
                    int curcol=node.second+dy[j];
                    if(currow >= n || currow < 0 || curcol >= m || curcol < 0)continue;
                    if(vis[currow][curcol] == 0 && grid[currow][curcol] == '1'){
                        q.push({currow,curcol});
                        vis[currow][curcol]=1;
                    }
                }
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int> > vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    bfs(i,j,grid,vis);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};