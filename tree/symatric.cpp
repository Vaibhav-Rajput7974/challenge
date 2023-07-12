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
bool Helper(TreeNode* r1,TreeNode* r2)
{
    if(!r1 && !r2)
        return true;
    else if(!r1 || !r2)
        return false;
    
    if(r1->val != r2->val)
        return false;

    return Helper(r1->left,r2->right) && Helper(r1->right,r2->left);
}
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return Helper(root->left,root->right);
    }
};