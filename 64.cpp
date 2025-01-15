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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        calcSum(root, maxi);
        return maxi;
    }
    int calcSum(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        } 
        int ls = max(0,calcSum(root->left, maxi));
        int rs = max(calcSum(root->right, maxi),0);
        maxi = max(maxi, ls+rs+root->val);
        return root->val+max(ls, rs);
    }
};