class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1 && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int rn=r+drow[i];
                int cn=c+dcol[i];
                if(rn>=0 && rn<n && cn>=0 && cn<m && grid[rn][cn]==1 && vis[rn][cn]==0){
                    q.push({rn,cn});
                    vis[rn][cn]=1;
                }
            }

        }
      
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};