
#include<bits/stdc++.h>
using namespace std;class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //vector<int> mini(prices.size(),0);
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<prices.size();i++){
            mini=min(prices[i],mini);
            maxi=max(maxi,prices[i]-mini);
        }
        return maxi<=0?0:maxi;
    }
};