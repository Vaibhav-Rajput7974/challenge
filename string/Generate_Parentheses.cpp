/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
    void helper(vector<string> &ans,string s,int n,int m){
        if(n == 0 && m == 0){
            ans.push_back(s);
            return;
        }
        if(m>0) helper(ans,s+')',n,m-1);
        if(n>0) helper(ans,s+'(',n-1,m+1);
    }
};