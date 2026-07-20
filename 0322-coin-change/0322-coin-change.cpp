class Solution {
public:
    int f(int i,int amt,vector<int>& coins,vector<vector<int>>&dp){
        if(amt==0) return 0;
        if(i==coins.size()) return 1e9;
        if(dp[i][amt]!=-1) return dp[i][amt];

        int nottaken = f(i+1,amt,coins,dp);
        int taken = 1e9;
        if(coins[i]<=amt){
             int res = f(i,amt-coins[i],coins,dp);
            if(res != 1e9) taken = 1 + res;
        }
        dp[i][amt] = min(taken,nottaken);
        return dp[i][amt];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = f(0,amount,coins,dp);
        return ans>=1e9 ? -1 : ans;
    }
};