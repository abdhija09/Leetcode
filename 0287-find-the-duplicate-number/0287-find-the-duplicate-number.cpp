class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=nums[0];
        for(int i=1;i<nums.size();i++){
           if(c==nums[i]){
            return nums[i];
           }
           c=nums[i];
        }
        return c;
    }
};