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
    unordered_map<int,int> inMap;

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];
        int numsLeft = inRoot - inStart;//that are left

        root->left = build(preorder, preStart+1, preStart+numsLeft,
                            inorder, inStart, inRoot-1);
        root->right = build(preorder, preStart+numsLeft+1, preEnd,
                             inorder, inRoot+1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;//search where the root value sits 
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};