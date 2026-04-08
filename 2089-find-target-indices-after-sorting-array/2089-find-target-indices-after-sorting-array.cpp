class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> p;

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
                high = mid - 1;
            }
        }

        int start = low;
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
                low = mid + 1;
            }
        }

        int end = high;

        for(int i = start; i <= end; i++){
            p.push_back(i);
        }

        return p;
    }
};