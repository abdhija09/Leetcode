/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        TreeNode* cur=root;
        if(cur==NULL) return;
        flatten(cur->right);
        flatten(cur->left);
        cur->right=prev;
        cur->left=NULL;
        prev=cur;

    }
};