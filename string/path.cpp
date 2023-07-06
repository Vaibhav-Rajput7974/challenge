/*
split the path by /
and then cheak if it is .. than pop that curent directary else
push the dircetary name
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        for(int i=0;i<path.size();){
            string cur="";
            int j=i;
            j++;
            while(j<path.size() && (path[j] != '/')){
                cur+=path[j];
                j++;
            }
            if(!st.empty() && cur == ".."){
                st.pop_back();
            }
            else if(cur != "." && cur != "" && cur!= ".."){
                st.push_back(cur);
            }
            i=j;
        }
        string ans="";
        for(auto it: st){
            ans=ans+"/"+it;
        }
        return ans.empty() ? "/" :ans;
    }
};