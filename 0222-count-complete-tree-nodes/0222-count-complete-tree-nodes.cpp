class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            count++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return count;
    }
};