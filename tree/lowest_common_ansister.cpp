/*
    APPROCH 1
    we will consider every node as root node and then from there we will cheak is the 
    if one node is in it left subtree and the other in its right subtree or not 
    if it have then it is over lowest common ansister else we will so to the node which have the both 
    and then cheak there 

    APPROCH 2
    as we know the lowest common ansister is the node which have same left child as the p and right as p 
    which mean it is the lowset common node in the path from root to that node 
    and same for q

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root==p || root==q)return root;
        TreeNode* l,*r;
        l = lowestCommonAncestor(root->left,p,q);
        r= lowestCommonAncestor(root->right,p,q);
        if(l && r)return root;
        if(l)return l;
        if(r) return r;
        return NULL;
    }
};

class Solution1 {
public:
    void create(TreeNode* root,map<TreeNode*,TreeNode*> &mp,TreeNode* pre){
        if(root == NULL){
            return ;
        }
        create(root->left,mp,root);
        mp[root]=pre;
        create(root->right,mp,root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*,TreeNode*> mp;
        create(root,mp,NULL);
        set<int> st;
        while(q){
            st.insert(q->val);
            q=mp[q];
        }
        while(p){
            if(st.find(p->val) != st.end()){
                return p;
            }
            st.insert(p->val);
            p=mp[p];
        }
        return NULL;
    }
};