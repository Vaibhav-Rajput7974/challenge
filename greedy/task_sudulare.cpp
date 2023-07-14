/*
we can see that our answer is equal to the sum of total task we have and the ideal position 
and we also know that out maximum frequest element will be sedule first after that we can sedula any element till it gets avilabe 
so totol ideal poisition after sedualing on 1 element equal to 

 A _ _ A _ _ A _ _ A _ _ B
 show total ideal = frequency of the element -1 * time ;

 
 Input: tasks = ["A","A","A","B","B","B"], n = 2
*/
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto it:tasks){
            freq[it-'A']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int ideal=(freq[0]-1)*n;
        for(int i=1;i<26;i++){
            ideal=ideal-min(freq[0]-1,freq[i]);
        }
        return tasks.size()+max(0,ideal);
    }
};