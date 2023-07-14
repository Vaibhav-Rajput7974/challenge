/*
    We are going to start creating out array from any one of the end point it may be start or the end
    so to search we know both start and end have only one adjacent element rest all have two 
    so we will find any one of the element which have one ahj element and build the array by going to it adjacent
    
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        map<int,vector<int> > mp;
        for(auto it:adj){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        int first=0;
        for(auto it:mp){
            if(it.second.size() == 1){
                first=it.first;
                break;
            }
        }
        int totalsz=adj.size()+1;
        ans.push_back(first);
        int pre=-1;
        int lastone=first;
        while(ans.size() < totalsz){
            if(mp[lastone].size() == 1){
                ans.push_back(mp[lastone][0]);
                pre=lastone;
                lastone=mp[lastone][0];
            }
            else{
                int f=mp[lastone][0];
                int s=mp[lastone][1];

                int Topush = f == pre ? s : f;
                ans.push_back(Topush);
                pre=lastone;
                lastone=Topush;
            }
        }
        return ans;

    }
};