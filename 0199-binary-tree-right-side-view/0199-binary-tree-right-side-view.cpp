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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>res;
        vector<vector<int>>ans;
        if(root==NULL) return res;
        q.push(root);
 while(!q.empty()){
            
            int size=q.size();
            vector<int>lvl;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                lvl.push_back(node->val);
            }
            ans.push_back(lvl);
        }
        int n=ans.size();
        for(int i=0;i<n;i++){
            int m=ans[i].size();
            res.push_back(ans[i][m-1]);
        }
      return res;
    }
};