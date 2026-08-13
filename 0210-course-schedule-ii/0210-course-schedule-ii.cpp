class Solution {
public:
    bool detect(int node, vector<int>& ans, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(!detect(it, ans, adj, vis, pathVis)) return false;
            }
            else if(pathVis[it]) return false; 
        }
        pathVis[node]=0;
        ans.push_back(node); 
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto& p : prerequisites) adj[p[0]].push_back(p[1]);

        vector<int> ans;
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!detect(i, ans, adj, vis, pathVis)) return {};
            }
        }
        return ans;
    }
};