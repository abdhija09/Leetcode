class Solution {
public:
    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> adj[n + 1];

        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n + 1, 1e18);
        vector<int> ways(n + 1, 0);

        pq.push({0, 0});

        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            long long time = it.first;
            int node = it.second;

            for(auto ad : adj[node]) {

                int adjnode = ad.first;
                int wt = ad.second;

                if(time + wt < dist[adjnode]) {

                    dist[adjnode] = time + wt;
                    ways[adjnode] = ways[node];

                    pq.push({dist[adjnode], adjnode});
                }

                else if(time + wt == dist[adjnode]) {

                    ways[adjnode] =
                        (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};