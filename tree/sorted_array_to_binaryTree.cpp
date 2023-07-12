struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<bits/stdc++.h>
using namespace std;
/*
    We Know that the mi element of tree is the root of the tree
    
    Input: nums = [-10,-3,0,5,9]

*/
class Solution {
public:
    TreeNode* helper(int s,int e,vector<int>&nums){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(s,mid-1,nums);
        root->right=helper(mid+1,e,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0,nums.size()-1,nums);
    }
};