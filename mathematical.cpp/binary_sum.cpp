/*
we are goin to add 2 binary number by useing the intuation
    1.a+b+carry == 0    ans=0, carray=0
    2.a+b+carry == 1    ans=1, carray=0
    3.a+b+carry == 2    ans=0, carray=1
    4.a+b+carry == 3    ans=1, carray=1
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i1=a.length()-1;
        int i2=b.length()-1;
        int carry=0;
        while(i1 >= 0 && i2>= 0){
            int cur = ((a[i1]-'0')+(b[i2]-'0')+carry);
            if(cur == 1){
                ans+="1";
                carry=0;
            }
            else if(cur == 2){
                ans+="0";
                carry=1;
            }
            else if(cur == 0){
                ans+="0";
                carry=0;
            }
            else{
                ans+="1";
                carry=1;
            }
            i1--;
            i2--;
        }
        while(i1>=0){
            int cur = ((a[i1]-'0')+carry);
            if(cur == 1){
                ans+="1";
                carry=0;
            }
            else if(cur == 0){
                ans+="0";
                carry=0;
            }
            else if(cur == 2){
                ans+="0";
                carry=1;
            }
            i1--;
        }
        while(i2>=0){
            int cur = ((b[i2]-'0')+carry);
            if(cur == 1){
                ans+="1";
                carry=0;
            }
            else if(cur == 0){
                ans+="0";
                carry=0;
            }
            else if(cur == 2){
                ans+="0";
                carry=1;
            }
            i2--;
        }
        if(carry){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};