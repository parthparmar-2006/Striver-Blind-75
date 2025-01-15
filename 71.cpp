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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int start = min(p->val, q->val);
        int end = max(p->val, q->val);
        TreeNode* ans = nullptr;
        while (root) {
            if (root->val >= start && root->val <= end) {
                ans = root;
                break;
            } else if (root->val <= start && root->val <= end) {
                root = root->right;
            } else root = root->left;
        } return ans;
    }
}; 