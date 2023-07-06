/*
    Simplay slid the window for the frequency
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool cheak(vector<int> &v,vector<int> &pfre){
        for(int i=0;i<26;i++){
            if(v[i] < pfre[i]){
                return false;
            }
        }
        return true;
    }
    string smallestWindow (string s, string p)
    {
        // Your code here
        int l=0;
        int r=0;
        vector<int> v(26,0);
        vector<int> pfre(26,0);
        int len=s.length();
        for(int i=0;i<p.length();i++){
            pfre[p[i]-'a']++;
        }
        string ans=s+"s";
        while(r < s.length()){
            v[s[r]-'a']++;
            r++;
            while(l< r && cheak(v,pfre)){
                len=min(len,r-l);
                //cout<<l<<"  "<<len<<endl;
                if(ans.length() > len){
                    ans=s.substr(l,len);
                }
                v[s[l]-'a']--;
                l++;
            }
        }
        return ans == s+"s" ?"-1" :ans;
    }
};