class Solution {
public:
    bool detect(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(detect(it, adj, vis, pathVis)) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto& p : prerequisites) adj[p[0]].push_back(p[1]);

        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detect(i,adj,vis,pathVis)) return false;
            }
        }
        return true;
    }
};