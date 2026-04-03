class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int count=1;
        int ans;
        if(nums.size()==1){
            ans=nums[0];
            return ans;
        }
        
        for(int i=0;i<nums.size()-1;i++){
           if(nums[i]==nums[i+1] && nums[i]==1){
           count++;
           maxi=max(maxi,count);
           }
           else{
            count=1;
           }
            
        }
        nums.erase(remove(nums.begin(),nums.end(),0),nums.end());
        if(nums.size()==1){
            ans=1;
            return ans;
        }
        if(nums.size()>0 && maxi==0){
            ans=1;
            return ans;
        }
        return maxi;
    }
};