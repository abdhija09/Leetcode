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
    vector<vector<int> >rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        q.push(root);
 while(!q.empty()){
            
            int size=q.size();
            vector<int>lvl;
            bool anyReal=false;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node==NULL){
                    lvl.push_back(INT_MIN);
                    continue;
                }
                anyReal=true;
                lvl.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if(!anyReal) break;
            ans.push_back(lvl);
        }
     
      return ans;
    }
    bool mirror(vector<int>&arr){
        int n=arr.size();
        int l=0,r=n-1;
        bool ok=true;
        while(l<=r){
            if(arr[l]!=arr[r]) return false;
            l++;
            r--;
        }
        return ok;
    }
    bool isSymmetric(TreeNode* root) {
       vector<vector<int>>temp=rightSideView(root);
       int m=temp.size();
       bool b=true;
       for(int i=0;i<m;i++){
          if(!mirror(temp[i])) return false;
       }
       return b;
    }

};