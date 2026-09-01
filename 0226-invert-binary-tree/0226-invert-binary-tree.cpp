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
   TreeNode* bfs(TreeNode* root){
    TreeNode* head=root;
    if(head==NULL) return NULL;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        bfs(root->left);
        bfs(root->right);
        return head;

   }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* head=bfs(root);
        return head;

    }
};