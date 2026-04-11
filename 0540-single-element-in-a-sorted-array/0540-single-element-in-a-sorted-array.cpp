class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[low] <= nums[mid]) {
                if (low + 1 < n && nums[low] == nums[low + 1]) {
                    low += 2;       
                } else {
                    ans = nums[low];   
                    break;
                }
            } else {
                if (mid + 1 < n && nums[mid] == nums[mid + 1]) {
                    mid += 2;
                    low = mid;        
                } else {
                    ans = nums[mid];    
                    break;
                }
            }
        }
        return ans;
    }
};