class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0 && vis[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    dist[i][j]=0;
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int rn=r+drow[i];
                int cn=c+dcol[i];
                if(rn>=0 && rn<n && cn>=0 && cn<m && mat[rn][cn]==1 && vis[rn][cn]==0){
                    q.push({{rn,cn},d+1});
                    dist[rn][cn]=d+1;
                    vis[rn][cn]=1;
                }
            }
        }
      return dist;  
    }
};