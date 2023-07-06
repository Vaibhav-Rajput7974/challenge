#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        int i=0;
        while(i<s.length()){
            if(s[i] == ' '){
                i++;
                continue;
            }
            string cur="";
                while(i<s.length() && s[i] != ' '){
                cur+=s[i];
                i++;
            }
            
            st.push(cur);
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()) ans+=" ";
        }
        return ans;
    }
};