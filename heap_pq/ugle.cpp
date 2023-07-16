/*

we can see that the ugle number is the multiple of 2 and 3 and 5 

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long> ,greater<long long> > pq;
        pq.push(1);
        int cnt=0;
        int ans=1;
        int pre=0;
        while(cnt<n){
            while(pre == pq.top())pq.pop();
            ans=pq.top();
            pq.pop();
            pre=ans;
            cnt++;

            pq.push(1ll*ans*2);
            pq.push(1ll*ans*3);
            pq.push(1ll*ans*5);
        }
        return ans;
    }
};