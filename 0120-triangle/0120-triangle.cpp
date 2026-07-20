class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& triangle){
        if(i==0 &&j==0) return  triangle[0][0];
        if(i<0 || j<0) return 1e9;
         if(triangle[i][j]==100000) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
       
        int up = triangle[i][j] + f(i-1, j, dp, triangle);
        int down = triangle[i][j] + f(i-1, j-1, dp, triangle);
       dp[i][j]=min(up,down);
       return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
         vector<vector<int>> dp(m, vector<int>(n, -1));
         for(auto &row : triangle){
         row.resize(n, 100000);} 
        int best = 1e9;
        for(int j=n-1; j>=0; j--){
            best = min(best, f(m-1, j, dp, triangle));
        }
        return best;
         
    }
};