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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = new TreeNode(val);
        if(root == NULL) return cur;

        TreeNode* node = root;
        TreeNode* parent = NULL;
 while(node != NULL){
            parent=node;
            if(node->val < val){
                node = node->right;
            }
            else if(node->val > val){
                node = node->left;
            }
        }

        if(parent->val < val){
            parent->right = cur;
        }
        else{
            parent->left = cur;
        }

        return root;
    }
};