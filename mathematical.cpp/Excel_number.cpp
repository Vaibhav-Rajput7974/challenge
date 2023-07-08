/*
    convert the number to to exel number
    a -> 1
    b -> 2
    c -> 3
    d -> 4
    e -> 5
    f -> 6
    g -> 7
    .....
    z -> z
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber){
            if(columnNumber%26 == 0){
                ans +='Z';
                columnNumber--;
            }
            else{
                ans+= (columnNumber%26-1)+'A';
            }
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};