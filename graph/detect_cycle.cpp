/*
    we are going to visit the node which are not visited 
    and if the node is visited then we are going to cheak that is the cur not have the parent child relation if not 
    we have found the cycle 
    else 
    there is no cycle
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int sr,vector<int> adj[],vector<int> &vis){
        vis[sr]=1;
        queue<pair<int,int>> q;
        q.push({sr,-1});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int a=node.first;
            int par=node.second;
            for(auto it:adj[a]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,a});
                }
                else if(it != par){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int >vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis))return true;
            }
        }
        return false;
    }
};