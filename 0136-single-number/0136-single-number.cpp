class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int,int>hash;
       int ans;
       if(nums.size()==1) {
        ans=nums[0];
        return ans;
       }
       for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
       }
       nums.erase(unique(nums.begin(),nums.end()),nums.end()); 
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        if(hash[nums[i]]==1) {
            ans=nums[i]; 
            return ans;
        }
       }
       return ans;
    }
};