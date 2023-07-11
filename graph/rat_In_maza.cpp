#include <bits/stdc++.h>
using namespace std;
 
class Solution{
    public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    char ch[4]={'D','L','U','R'};
    void dfs(int row,int col,string cur,vector<vector<int>> &m, int n,vector<vector<int> > &vis,vector<string> &ans){
        if(row == n-1 && col == n-1){
            ans.push_back(cur);
            return ;
        }
        for(int i=0;i<4;i++){
            int curx=row+dx[i];
            int cury=col+dy[i];
            if(curx< 0 || curx>=n || cury< 0 || cury>=n)continue;
            if(vis[curx][cury] == 0 && m[curx][cury] == 1){
                vis[curx][cury]=1;
                dfs(curx,cury,cur+ch[i],m,n,vis,ans);
               //cur.pop_back();
                vis[curx][cury]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        if(m[0][0] == 0) {
            return ans;
        }
        vector<vector<int> > vis(n,vector<int> (n,0));
        vis[0][0]=1;
        dfs(0,0,"",m,n,vis,ans);
        return ans;
    }
};
