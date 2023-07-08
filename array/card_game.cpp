/*
    we have to remove a card from the end or starting 
    if we want to remove 3 card 
    so if we remove 1 card from starting and then remove 1 card from the end and then remove 2 card from the start
    so it is same a removeing 2 card from the starting and then removeing 1 from the end 

    useing this patten we can use the sliding window approch to solve this problem 
    we are going to push all the 3 cards in the window after that we are going to remove a card from the window and add a card in it from the end
     
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int temp=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            temp+=cardPoints[i];
        }
        ans=max(ans,temp);
        for(int i=k-1;i>=0;i--){
            temp=temp-cardPoints[i];
            temp+=cardPoints[n-k+i];
            ans=max(ans,temp);
        }
        return ans;
    }
};