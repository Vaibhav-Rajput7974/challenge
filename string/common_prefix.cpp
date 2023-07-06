#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            string cur="";
            for(int j=0;j<strs[i].size() && j<ans.size();j++){
                if(strs[i][j] == ans[j]){
                    cur+=strs[i][j];
                }
                else{
                    break;
                }
            }
            ans=cur;
        }
        return ans;
    }
};