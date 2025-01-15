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
    TreeNode* buildRecursively(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& mp) {
        if (inStart>inEnd || postStart>postEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[postorder[postEnd]];
        int numsLeft = inRoot - inStart;
        root->left = buildRecursively(inorder, inStart, inRoot-1, postorder, postStart, postStart+numsLeft-1, mp);
        root->right = buildRecursively(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()!=postorder.size() || inorder.empty() || postorder.empty()) return nullptr;
        unordered_map<int, int> mp;
        for (int i=0; i<inorder.size(); i++) mp[inorder[i]]=i;
        TreeNode* root = buildRecursively(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
        return root;
    }
};