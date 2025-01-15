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
    bool helper(TreeNode* root, long start, long end) {
        if (!root) return true;
        if (root->val <= start || root->val >= end) return false;
        return (helper(root->left, start, root->val) && helper(root->right, root->val, end));
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};