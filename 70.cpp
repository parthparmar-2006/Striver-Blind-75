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
    void helper(TreeNode* root, int k, int& i, int& ans) {
        if (!root) return;
        helper(root->left, k, i, ans);
        if (++i==k) {
            ans = root->val;
            return;
        }
        helper(root->right, k, i, ans);
    };
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = -1;
        helper(root, k ,i, ans);
        return ans;
    }
};