class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> ans(k, 0);
        vector<long long> prev(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> curr(k, 0);

            int r = nums[i] % k;

            // Subarray containing only nums[i]
            curr[r]++;

            // Extend previous subarrays
            for (int j = 0; j < k; j++) {
                int rem = (1LL * j * r) % k;
                curr[rem] += prev[j];
            }

            // Add counts to final answer
            for (int j = 0; j < k; j++) {
                ans[j] += curr[j];
            }

            prev = curr;
        }

        return ans;
    }
};