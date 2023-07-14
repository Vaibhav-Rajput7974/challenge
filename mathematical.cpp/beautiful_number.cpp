/*
        We are going to use flood algorithm to find cycle in the loop 
        if cycle is not then return true else false;
        slow move 1 postion at a time 
        fast move 2 position 
        2wwwwwwwwwwz
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int convert(int n){
    int ans=0;
    while(n){
        int d=n%10;
        ans+=(d*d);
        n/=10;
    }
    return ans;
}
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while(true){
            //if(slow == fast)return false;
            slow=convert(slow);
            fast=convert(convert(fast));
            if(slow == 1 || fast == 1){
                return true;
            }
            else if(slow == fast){
                return false;
            }
        }
        return true;
    }
};