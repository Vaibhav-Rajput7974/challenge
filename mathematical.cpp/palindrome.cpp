/*
Input: x = 121
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x< 0)return false;
        int dup=x;
        long long ans=0;
        while(dup){
            ans=ans*10+(dup%10);
            dup/=10;
        }
        return x == ans;
    }
};