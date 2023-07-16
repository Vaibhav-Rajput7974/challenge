/*
    we will first try to use the bricks and if we cant use the brick then we will try
    replace the maximume bricks use using a ladder and we will continue this untill we have used all ladder and brick

    
    heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int dif=0;
        int i;
        for(i=0;i<heights.size()-1;i++){
            dif=heights[i+1]-heights[i];
            if(dif <= 0)continue;
            bricks-=dif;
            pq.push(dif);
            if(bricks < 0){
                bricks+=pq.top();
                pq.pop();
                ladders--;
            }
            if(ladders < 0)break;
        }
        return i;
    }
};