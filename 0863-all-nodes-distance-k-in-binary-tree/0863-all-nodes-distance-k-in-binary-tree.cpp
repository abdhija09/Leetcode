/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left){
            parent[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            q.push(node->right);
        }
       }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       map<TreeNode*,bool>visted;
       queue<TreeNode*>queue;
       unordered_map<TreeNode*,TreeNode*>parent;
       markparents(root,parent);
       queue.push(target);
       int lvl=0;
       visted[target]=true;
       while(!queue.empty()){
        int size=queue.size();
        if(lvl==k) break;
        for(int i=0;i<size;i++){
        TreeNode* curr=queue.front();
      
        queue.pop();
        if(curr->left && !visted[curr->left]){
            visted[curr->left]=true;
            queue.push(curr->left);
        }
        if(curr->right && !visted[curr->right]){
            visted[curr->right]=true;
            queue.push(curr->right);
        }
        if(parent[curr] && !visted[parent[curr]]){
            queue.push(parent[curr]);
            visted[parent[curr]]=true;
        }
       
        }
         lvl++;
       }
    vector<int>res;
    while(!queue.empty()){
        TreeNode* node=queue.front();
        queue.pop();
        res.push_back(node->val);
    }
 return res;
    }
};