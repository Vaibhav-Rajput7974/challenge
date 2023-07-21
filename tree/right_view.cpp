/*
the last most element of evey level will be the the right most most element of the tree
*/
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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return {};
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur != NULL){
                if(q.front() == NULL)ans.push_back(cur->val);
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                if(cur->right != NULL){
                    q.push(cur->right);
                }
            }
            else if(!q.empty()){
                q.push(NULL);
            }
        }
        return ans;
    }
};