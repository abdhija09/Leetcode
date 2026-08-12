class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        queue<pair<int,int>>q;//{{r,c}}
        int n=image.size();
        int m=image[0].size();
        int in=image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({sr,sc});
        vis[sr][sc]=color;
        ans[sr][sc]=color;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
           int r=q.front().first;
           int c=q.front().second;
           q.pop();
           for(int i=0;i<4;i++){
             int rn=r+drow[i];
            int cn=c+dcol[i];
            if(rn>=0 && rn<n && cn>=0 && cn<m && image[rn][cn]==in && vis[rn][cn]!=color){
                  vis[rn][cn]=color;
                  ans[rn][cn]=color;
                  q.push({rn,cn});
            }
           }
          
        }
        return ans;
    }
};