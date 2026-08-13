class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int rn=r+drow[k];
                            int cn=c+dcol[k];
                            if(rn>=0 && rn<n && cn>=0 && cn<m && grid[rn][cn]=='1' && vis[rn][cn]==0){
                                q.push({rn,cn});
                                vis[rn][cn]=1;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};