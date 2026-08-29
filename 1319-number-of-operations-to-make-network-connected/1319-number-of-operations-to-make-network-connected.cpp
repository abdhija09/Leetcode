class Solution {
public:
    
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {   
            int node = q.front();
            q.pop();

            for (int neigh: adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if (connections.size() < n - 1) return -1;
        vector<bool>visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                bfs(i, adj, visited); 
            }
        }

        return components - 1;
    }

    
};