/*
    useing backtrack we are going to find out all the combination possible
    we are going to first push that elemt to our answer and if form the valid combination then push that to out answer 
    after that pop element from cur array useing backtrack 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int> > ans;
void helper(vector<int> &can,int target,vector<int> &cur ,int idx){
    if(idx >= can.size()){
        if(target == 0){
            ans.push_back(cur);
        }
        return ;
    }
    if(target <= 0){
        if(target == 0)
        ans.push_back(cur);
        return ;
    }
    cur.push_back(can[idx]);
    helper(can,target-can[idx],cur,idx+1);
    cur.pop_back();
    while(idx < can.size()-1 && can[idx] == can[idx+1]){
        idx++;
    }
    helper(can,target,cur,idx+1);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        helper(candidates,target,cur,0);
        
        
        return ans;
    }
};