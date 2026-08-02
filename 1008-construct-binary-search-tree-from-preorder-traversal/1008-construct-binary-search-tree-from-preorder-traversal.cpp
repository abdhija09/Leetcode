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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]); 

        for (int i = 1; i < preorder.size(); i++) {   
            TreeNode* cur = root;
            TreeNode* par = NULL;

            while (cur != NULL) {                   
                par = cur;
                if (preorder[i] < cur->val) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }

            TreeNode* prev = new TreeNode(preorder[i]);
            if (preorder[i] < par->val) {            
                par->left = prev;
            } else {
                par->right = prev;
            }
        }

        return root;                                
    }
};