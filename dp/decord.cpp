/*
decord the message 

 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(string s,int idx,vector<int> &dp){
    if(s.length() == 0){
        return 1;
    }
    if(s[0] == '0'){
        return 0;
    }
    if(dp[idx] != 0){
        return dp[idx];
    }
    //int ans=0;
    int num=0;
    //cout<<idx<<"  "<<s[0];
    for(int i=0;i<s.length();i++){
        num=num*10 + (s[i]-'0');
        if(num >0 && num <= 26){
            dp[idx]+=helper(s.substr(i+1),i+idx+1,dp);
        }else{
            break;
        }
    }
    return dp[idx];
}
    int numDecodings(string s) {
        vector<int> dp(s.length(),0);
        return helper(s,0,dp);
    }
};