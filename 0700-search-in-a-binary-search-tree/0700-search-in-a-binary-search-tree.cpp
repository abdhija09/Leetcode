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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        TreeNode* prev =NULL;
        if(root->val==val) {
             prev=root;
             return prev;
        }
        if(root->val>val){
            TreeNode* cur=root;
            prev=searchBST(cur->left,val);
        }
        else{
            TreeNode* cur=root;
            prev=searchBST(cur->right,val);
        }
       return prev; 
    }
};