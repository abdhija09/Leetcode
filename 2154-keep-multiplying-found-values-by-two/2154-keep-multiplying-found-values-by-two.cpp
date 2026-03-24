class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans = original;
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == original) {
                original *= 2;
                ans = original;
                i = 0;   
            } else {
                i++;    
            }
        }

        return ans;
    }
};