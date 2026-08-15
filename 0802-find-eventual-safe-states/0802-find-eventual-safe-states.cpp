class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> outdegree(n,0);
        vector<vector<int>> radj(n);
        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
            for(auto it:graph[i]){
                radj[it].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) q.push(i);
        }
        vector<int>safe(n,0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe[node]=1;
            for(auto it: radj[node]){
                outdegree[it]--;
                if(outdegree[it]==0) q.push(it);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};