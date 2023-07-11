
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        queue<pair<int,int> > q;
        vector<vector<int> > vis(image.size(),vector<int> (image[0].size(),0));
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int curx=node.first+dx[j];
                    int cury=node.second+dy[j];
                    if(curx < 0 || curx >= image.size() || cury < 0 || cury >= image[0].size())continue;
                    if(image[node.first][node.second] == image[curx][cury] && vis[curx][cury] == 0){
                        q.push({curx,cury});
                        vis[curx][cury]=1;
                    }
                }
                image[node.first][node.second]=color;
            }
        }
        return image;
    }
};