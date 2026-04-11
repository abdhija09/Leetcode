class Solution {
public:
    bool possible(vector<int>& nums,int low,int threshold){
        bool ok;
        int count=0;
        for(int i=0;i<nums.size();i++){
           count+=ceil((double)nums[i]/low);
        }
        if(count<=threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=-1;
        int low=1,high=*max_element(nums.begin(),nums.end());
          while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums,mid,threshold)==true){
                ans=mid;
                high=mid-1;
            }

            else low=mid+1;
        }
     return ans;
    }
};
