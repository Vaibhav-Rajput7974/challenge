/*
We are going to store the k smallest element in  heap then 
we will cheak if our heap size is greater then the k then we will pop the largest element 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                pq.push(matrix[i][j]);
                while(pq.size()>k)pq.pop();
            }
        }
        return pq.top();
    }
};