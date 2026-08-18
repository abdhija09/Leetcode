class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int ans=0;
        vector<int>dist(n+1,1e9);
        queue<pair<int,pair<int,int>>>q;//{a,{b,c}}
        dist[k]=0;
        q.push({1,{k,0}});//{reached,{node,time}};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.second.first;
            int vis=it.first;
            int time=it.second.second;
            for(auto ad:adj[node]){
                int adjnode=ad.first;
                int wt=ad.second;
                if(wt+time<dist[adjnode]){
                    dist[adjnode]=wt+time;
                    q.push({vis+1,{adjnode,wt+time}});
                }
            }
        }
    
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }

    return ans;
    }
};