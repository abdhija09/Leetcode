class Solution {
public:
    int f(int i,int amt,vector<int>& coins,vector<vector<int>>&dp){
        if(amt==0) return 1;
         if(i<0) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int nottaken=f(i-1,amt,coins,dp);
        int taken=0;
        if(coins[i]<=amt){
          taken=f(i,amt-coins[i],coins,dp);
        }
        dp[i][amt]=taken+nottaken;
        return dp[i][amt];
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};