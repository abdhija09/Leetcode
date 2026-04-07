class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> t = {-1, -1};
        int n = nums.size();

        // find first occurrence
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                t[0] = mid;
                high = mid - 1;
            }
        }

        low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                t[1] = mid;
                low = mid + 1;
            }
        }

        return t;
    }
};