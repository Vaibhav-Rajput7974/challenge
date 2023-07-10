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
    bool helper(TreeNode* root,TreeNode* subroot){
        if(root == NULL && subroot == NULL){
            return true;;
        }
         else if(root == NULL || subroot == NULL  || root->val != subroot->val){
            return false;
        }
        if(!helper(root->left,subroot->left))return false;
        if(!helper(root->right,subroot->right))return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
       if(root == NULL)return NULL;
       if(root->val == subroot->val){
           if(helper(root,subroot))return true;
       }
       return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
    }
};