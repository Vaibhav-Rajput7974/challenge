/*
we will find the best time to sell and buy stock 
or it will be same if the stoke price of previse day is greater then the other

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> dp;
    int maxProfit(vector<int>& prices) {
        int total=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1] <prices[i]){
                total+=prices[i]-prices[i-1];
            }
        }
        return total;
    }
};