/*
    we have to rearrange the string in such a way that two consiquetive element are not the same 
    so for that we are going to store there frequence in the char in map and order the element useing there frequence then we are going to usr the 
    two most frequenct element of the map and decrement there frequence by one if there frequence is greater then one then push them back to heap 
    continue this untill there is only one character left now cheak if it frequeny is greater then one then we can arrange that element in res
    so return ""
    else add it to our result and return it 
    
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char> > pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string res="";
        while(pq.size()>1){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            res+=top1.second;
            res+=top2.second;
            top1.first-=1;
            top2.first-=1;
            if(top1.first > 0){
                pq.push(top1);
            }
            if(top2.first > 0){
                pq.push(top2);
            }
        }
        if(!pq.empty()){
            if(pq.top().first>1){
                return "";
            }
            else{
                res+=pq.top().second;
            }
        }
        return res;
    }
};