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
vector<int>ans;
   void infix(TreeNode* root){
    ans.push_back(root->val);
    if(root->left) infix(root->left);
    if(root->right) infix(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
    int mimdiv=INT_MAX;

    infix(root);
   for(int i=0;i<ans.size();i++){
    for(int j=i+1;j<ans.size();j++){
        if(abs(ans[i]-ans[j])<mimdiv) mimdiv=abs(ans[i]-ans[j]);
    }
   }
      return mimdiv;
    }
};