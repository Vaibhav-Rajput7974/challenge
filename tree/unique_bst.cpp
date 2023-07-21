/*
we know that the element smaller then the root are in left subtree and greater are in the right sub tree 
so we are going to make evere node as root node then we will create the tree 


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
vector<TreeNode*> helper(int start,int end){
    if(start > end){
        return {NULL};
    }
    vector<TreeNode*> ans;
    for(int i=start;i<=end;i++){
        auto left=helper(start,i-1);
        auto right=helper(i+1,end);
        for(auto p:left){
            for(auto s:right){
                TreeNode* node=new TreeNode(i,p,s);
                ans.push_back(node);
            }
        }
    }
    return ans;

}
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};