class Solution {
public:
   
    int splitArray(vector<int>& nums, int k) {
        vector<vector<int>>c;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            c.clear();                          
            c.push_back(vector<int>());         
            int j=0,sum=0;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]<=mid){
                    c[j].push_back(nums[i]);    
                    sum+=nums[i];
                }
                else{
                    j++;
                    c.push_back(vector<int>()); 
                    c[j].push_back(nums[i]);
                    sum=nums[i];
                }
            }
            if(c.size()<=k){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};