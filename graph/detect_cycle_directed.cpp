/*
we will cheak if the element is already vis or not if it is vis then if it is in the current resursion or not if not then return false else return true
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> &vis,vector<int>&res,vector<int> adj[]){
        vis[node]=1;
        res[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,res,adj))return true;
            }
            else if(res[it])return true;
        }
        res[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> res(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,res,adj))return true;
            }
        }
        return false;
    }
};