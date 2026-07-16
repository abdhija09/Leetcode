class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(ind - 2, nums, dp);
        int notpick = 0 + f(ind - 1, nums, dp);
        return dp[ind] = max(pick, notpick);
    }

    int robline(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n, -1);
        return f(n - 1, nums, dp);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> excludelast(nums.begin(), nums.end() - 1);   
        vector<int> excludefirst(nums.begin() + 1, nums.end()); 

        return max(robline(excludelast), robline(excludefirst));
    }
};