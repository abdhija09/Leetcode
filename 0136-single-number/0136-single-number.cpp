
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int ans = 0;

        if(nums.size() == 1) return nums[0];

        for(int i = 0; i < nums.size() - 1; ) {

            if(nums[i] == nums[i + 1]) {
               
                nums.erase(nums.begin() + i, nums.begin() + i + 2);
               
            }
            else {
                ans = nums[i];
                return ans;
            }
        }

       ans= nums[0];
        return ans;
    }
};