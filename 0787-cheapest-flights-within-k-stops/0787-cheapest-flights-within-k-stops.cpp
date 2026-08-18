class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {src, 0}});
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int ds = it.first;
            int d = it.second.first;
            int stops = it.second.second;

            if (d == dst) return ds;
            if (stops > k) continue;         

            for (auto& edge : adj[d]) {
                int v = edge.first;
                int w = edge.second;
                if (ds + w < dist[v][stops+1]) {
                    dist[v][stops+1] = ds + w;
                    pq.push({ds + w, {v, stops+1}});
                }
            }
        }
        return -1;
    }
};