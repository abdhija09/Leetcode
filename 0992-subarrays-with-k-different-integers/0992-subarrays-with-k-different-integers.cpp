class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
    int l = 0, count = 0, n = nums.size();
    
    for (int r = 0; r < n; r++) {
        mpp[nums[r]]++;
        
        while (mpp.size() > k) {
            mpp[nums[l]]--;                 
            if (mpp[nums[l]] == 0) {        
                mpp.erase(nums[l]);
            }
            l++;
        }
        
        count += r - l + 1;                 
    }
    
    return count;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostKDistinct(nums,k)-atMostKDistinct(nums,k-1);
}
};