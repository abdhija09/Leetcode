class Solution {
public:
    int findPeakElement(vector<int>& nums) {
           int n = nums.size();
        int low = 0, high = n - 1;
        int mini = nums[0];
        int idx;
        vector<int>c={nums.begin(),nums.end()};
        sort(c.begin(),c.end());
        while (low <= high) {
            int mid = (low + high) / 2;

            if (c[low] <= c[mid]) {//identify the sorted array
                mini =max(mini, c[mid]);
                auto it = find(nums.begin(), nums.end(), mini);
                idx = it - nums.begin(); 
                low = mid + 1;
            }
            else {
                mini = max(mini, c[mid]);
                auto it = find(nums.begin(), nums.end(), mini);
                 idx = it - nums.begin(); 
                 high=mid-1;
                
            }
        }
        return idx;
    }
};