/*
                TWO POINTER
In this we are going to put to pointer to the two end of array and then goin to calculate the current container  
size and store that to the answer
after that we are going to cheak the pointer which have small value we are going to increase it

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int mani=min(height[start] ,height[end]);
        int length=end-start;
        int ans=length*mani;
        while(start < end)
        {
            if(height[start] < height[end])
            {
                start++;
            }
            else
            {
                end--;
            }
            int mani=min(height[start] ,height[end]);
            int length=end-start;
            int current=length*mani;
            ans=max(ans,current);
        }
        return ans;

    }
};