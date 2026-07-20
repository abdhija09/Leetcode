class Solution {
public:
    int f(int i,vector<int>& nums,int target,int totalsum,vector<vector<int>>&dp){
        if(i==nums.size()) return target==0 ? 1 : 0;
        int rem = 0;
        for(int j=i; j<nums.size(); j++) rem += nums[j];
        if(target >rem|| target < -rem) return 0;

        if(dp[i][target+totalsum]!=-1) return dp[i][target+totalsum];
        int neg=f(i+1,nums,target+nums[i],totalsum,dp);
        int pos=f(i+1,nums,target-nums[i],totalsum,dp);
        dp[i][target+totalsum]= neg+pos;
        return dp[i][target+totalsum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=0;
        for(int x: nums) totalsum+=x;
        if(target>totalsum || target<-totalsum) return 0;
        vector<vector<int>>dp(n, vector<int>(2*totalsum+1,-1));
        return f(0,nums,target,totalsum,dp);
    }
};