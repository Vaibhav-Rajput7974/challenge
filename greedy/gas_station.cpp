/*
    first cheak if it is possible to travel from any point or not 
    it is possible whene net gas - net cost >= 0 else not possible

    then cheak till every index that is it possible to travel if not or out value of current gas become o then
    increse the starting point to the next idx 
    
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curgas=0;
        int totalgas=0;
        int startidx=0;
        for(int i=0;i<gas.size();i++){
            curgas += (gas[i]-cost[i]);
            totalgas += (gas[i]-cost[i]);

            if(curgas < 0){
                startidx=i+1;
                curgas=0;
            }
        }
        return totalgas < 0 ? -1 : startidx;
    }
};