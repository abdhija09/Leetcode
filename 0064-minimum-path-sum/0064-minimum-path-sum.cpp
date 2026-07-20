class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0 ) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
      int  down=grid[i][j]+f(i-1,j,dp,grid);
      int right=grid[i][j]+f(i,j-1,dp,grid);
      dp[i][j]=min(down,right);
      return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m-1,n-1,dp,grid);
    }
};