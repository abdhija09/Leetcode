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
    void f(TreeNode* root, unordered_map<TreeNode*, pair<int,int>>&mp, pair<int,int> k){
       if(root==NULL) return;
       mp.insert({root,k});
       if(root->left!=NULL) f(root->left,mp,{k.first-1,k.second+1});
       if(root->right!=NULL) f(root->right,mp,{k.first+1,k.second+1});
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       unordered_map<TreeNode*, pair<int,int>> mp;
       f(root, mp, {0,0});

     map<int, vector<pair<int,int>>> grouped; 
     for(auto &entry : mp){
    TreeNode* key = entry.first;
    int col = entry.second.first;
    int row = entry.second.second;
    grouped[col].push_back({row, key->val});
}

vector<vector<int>> ans;
for(auto &g : grouped){
    sort(g.second.begin(), g.second.end());
    vector<int> vals;
    for(auto &p : g.second){
        vals.push_back(p.second);
    }
    ans.push_back(vals);
}
     return ans;   
    }   
};