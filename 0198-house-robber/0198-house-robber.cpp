class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size(); 
      int maxi=INT_MIN;
      if(n==1)return nums[0];
      if(n==2){
        int m=max(nums[0],nums[1]);
        return m;
      }
      int prev2 = nums[0];
      int prev1 = max(nums[0], nums[1]);
      for(int i=2;i<n;i++){
        int curr=max(prev1,prev2+nums[i]);
        prev2=prev1;
        prev1=curr;
      }
      return prev1;
    }
};