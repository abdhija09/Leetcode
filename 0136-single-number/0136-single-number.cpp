class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());  
        int ans;                        
        
        if(nums.size() == 1) return nums[0];  
        
        int i = 0;
        while(i < nums.size() - 1) {
            if(nums[i] == nums[i+1]) {
                
                nums.erase(nums.begin() + i, nums.begin() + i + 2);
                
            } else {
                
                ans = nums[i];
                return ans;
            }
        }
        
      
        return nums[0];
    }
};