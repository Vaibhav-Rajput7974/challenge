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
    void dfs(TreeNode* pre,TreeNode* root,map <TreeNode*,TreeNode*> &mp){
        if(root == NULL){
            return;
        }
        mp[root]=pre;
        dfs(root,root->left,mp);
        dfs(root,root->right,mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        set<TreeNode*> st;
        map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*> q;
        dfs(NULL,root,mp);
        q.push(target);
        st.insert(target);
        while(!q.empty() && k != 0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                if(node->left!=NULL && st.find(node->left) == st.end()) {
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right !=NULL && st.find(node->right) == st.end()){
                    q.push(node->right);
                    st.insert(node->right);
                }
                if(mp[node] != NULL && st.find(mp[node]) == st.end()){
                    q.push(mp[node]);
                    st.insert(mp[node]);
                }
            }
            k--;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        } 
        return ans;
    }
};