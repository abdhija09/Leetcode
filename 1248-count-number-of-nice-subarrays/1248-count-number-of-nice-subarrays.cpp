class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
    int atMost(vector<int>& nums, int k) {
        int l = 0, count = 0, result = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 == 1) count++;     
            
            while (count > k) {               
                if (nums[l] % 2 == 1) count--;
                l++;
            }
            
            result += r - l + 1;               
        }
        return result;
    }
};