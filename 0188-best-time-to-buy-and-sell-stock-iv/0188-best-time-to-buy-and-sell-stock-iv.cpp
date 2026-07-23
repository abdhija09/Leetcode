class Solution {
public:
   int f(int i,int buy,int ct,vector<int>& p,vector<vector<vector<int>>>&dp,int k){
    int n=p.size();
    if(i==n || ct==k) return 0;
    if(dp[i][buy][ct]!=-1) return dp[i][buy][ct];
    int profit;
    if(buy){
        profit=max(-p[i]+f(i+1,0,ct,p,dp,k), f(i+1,1,ct,p,dp,k));
    }
    else{
        profit=max(p[i]+f(i+1,1,ct+1,p,dp,k), f(i+1,0,ct,p,dp,k));
    }
    dp[i][buy][ct]=profit;
    return dp[i][buy][ct];
   }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return f(0,1,0,prices,dp,k);
    }
};