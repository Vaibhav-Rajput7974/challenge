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

class Solution {
public:
int preorder(TreeNode* root ,int low,int high,int &sum){
    if(root == NULL){
        return 0;
    }
    preorder(root->left,low,high,sum);
    int cur=root->val;
    if(cur >= low && cur<=high){
        sum+=cur;
    }
    preorder(root->right,low,high,sum);
    return cur;
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum1=0;
        preorder(root,low,high,sum1);
        return sum1;
    }
};