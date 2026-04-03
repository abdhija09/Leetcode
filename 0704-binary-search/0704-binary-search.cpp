class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int mid, ans = -1;

        while(low <= high) {
            mid = (low + high) / 2;

            if(nums[mid] == target) {    
                ans = mid;
                break;
            } else if(nums[mid] < target) { 
                low = mid + 1;
            } else {                        
                high = mid - 1;
            }
        }

        return ans;
    }
};