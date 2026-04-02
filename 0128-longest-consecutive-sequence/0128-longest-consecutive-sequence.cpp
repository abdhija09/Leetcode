class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int maxi = 1, current = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) continue;       
            if (nums[i] == nums[i-1] + 1) {           
                current++;
                maxi = max(maxi, current);
            } else {                                   
                current = 1;
            }
        }
        return maxi;
    }
};