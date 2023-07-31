/*
    given the range n and integer k find create all the combination of n size 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > res;
    void helper(int idx,int n,int k,vector<int> &ans){
        //if(idx > n)return ;
        if(k == 0){
            res.push_back(ans);
            return ;
        }
        for(int i=idx;i<=n;i++){
            ans.push_back(i);
            helper(i+1,n,k-1,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        helper(1,n,k,ans);
        return res;
    }
};