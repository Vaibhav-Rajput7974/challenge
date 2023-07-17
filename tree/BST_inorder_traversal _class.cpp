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

class BSTIterator {
public:
    stack<TreeNode*> st;

    void push(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        push(root);
    }

    int next() {
        auto temp=st.top();
        st.pop();
        push(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};