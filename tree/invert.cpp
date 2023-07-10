
 // Definition for a binary tree node.
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
TreeNode* helper(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    TreeNode* left=helper(root->left);
    TreeNode* right=helper(root->right);

    root->left=right;
    root->right=left;
    return root;
}
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};