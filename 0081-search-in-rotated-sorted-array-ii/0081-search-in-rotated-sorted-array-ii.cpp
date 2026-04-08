class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool ok=false;
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ok=true;
                return ok;
            }
          else if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
          }
          else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
              if(target>=nums[mid] && nums[high]>=target){
                low=mid+1;
              }
              else high=mid-1;
            }
        }
        
        return ok;
    }
};