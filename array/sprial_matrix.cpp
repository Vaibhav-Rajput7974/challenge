#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start_x=0;
        int end_x=matrix.size()-1;
        int start_y=0;
        int end_y=matrix[0].size()-1;
        int i=0;
        int j=0;
        bool cheak=true;
        vector<int> ans;
        while(start_x <= end_x && start_y <= end_y)
        {
            for(int i=start_x;i<=end_x;i++)
            {
                ans.push_back(matrix[start_y][i]);
            }
            start_y++;
            for(int i=start_y;i<=end_y;i++)
            {
                ans.push_back(matrix[i][end_x]);
            }
            end_x--;
            for(int i=end_x;i>=start_x;i--)
            {
                ans.push_back(matrix[end_y][i]);
            }
            end_y--;
            for(int i=end_y;i>=start_y;i--)
            {
                ans.push_back(matrix[i][start_x]);
            }
            start_x++;            
        }
        return ans;
    }
};