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
    vector<int>store(TreeNode* root){
        vector<int>ans;
        // ans.push_back(root->val);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
          
            for(int i=0;i<size;i++){
                  TreeNode* cur=q.front();
            q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                if(cur!=NULL) ans.push_back(cur->val);
               
            }
            
        }
        sort(ans.begin(),ans.end());
         return ans;  
        }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans=store(root);
        if(ans.size()==0) return 0;
        return ans[k-1];

    }
};