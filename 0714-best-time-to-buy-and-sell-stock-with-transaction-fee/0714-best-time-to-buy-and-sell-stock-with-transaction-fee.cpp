class Solution {
public:
   int f(int i,int buy,vector<int>& p,vector<vector<int>>&dp,int fee){
    int n=p.size();
    if(i>=n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit;
    if(buy){
        profit=max(-p[i]+f(i+1,0,p,dp,fee), f(i+1,1,p,dp,fee));
    }
    else{
        profit=max(p[i]-fee+f(i+1,1,p,dp,fee), f(i+1,0,p,dp,fee));
    }
    dp[i][buy]=profit;
    return dp[i][buy];
   }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp,fee);
    }
};