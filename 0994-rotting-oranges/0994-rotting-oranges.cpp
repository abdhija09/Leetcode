class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        int cntfrsh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)cntfrsh++;
            }
        }
        int tm=0;
        int cnt=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
           int r=q.front().first.first;
           int c=q.front().first.second;
           int t=q.front().second;
           q.pop();
           tm=max(tm,t);
           for(int i=0;i<4;i++){
            int rn=r+drow[i];
            int cn=c+dcol[i];
            if(rn>=0 && rn<n && cn >=0 && cn<m && vis[rn][cn]!=2 && grid[rn][cn]==1){
                q.push({{rn,cn},t+1});
                vis[rn][cn]=2;
                cnt++;
            }
           }
        }
        if(cnt!=cntfrsh) return -1;
        return tm;
    }
};