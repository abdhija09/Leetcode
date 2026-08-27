class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(auto it:edges){
            dist[it[0]][it[1]] = min(dist[it[0]][it[1]], it[2]);
            dist[it[1]][it[0]] = min(dist[it[1]][it[0]], it[2]);
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]<INF && dist[k][j]<INF){
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        queue<pair<int,int>> count;
        for(int i=0;i<n;i++){
            int reachable=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold) reachable++;
            }
            count.push({i, reachable});
        }

        int result = -1, minCount = INT_MAX;
        while(!count.empty()){
            pair<int,int> node = count.front();
            count.pop();
            int city = node.first;
            int ct = node.second;
            if(ct <= minCount){
                minCount = ct;
                result = city;
            }
        }
        return result;
    }
};