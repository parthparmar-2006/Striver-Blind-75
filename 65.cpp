#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root==NULL)return arr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for (int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if (node->right!=NULL)q.push(node->right);
                level.push_back(node->val);
            }
            arr.push_back(level);
        }return arr;
    }
};