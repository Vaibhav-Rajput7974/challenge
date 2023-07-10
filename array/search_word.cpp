/*
simple dfs to cheak

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool helper(int x,int y,vector<vector<char>>& board, string word,vector<vector<int>> &vis ){
    if(word.length() == 0){
        return true;
    }
    if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] != word[0] || vis[x][y] != 0){
        return false;
    }
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        if(helper(x+dx[i],y+dy[i],board,word.substr(1),vis)){
            return true;
        }
    }
    vis[x][y]=0;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(helper(i,j,board,word,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};