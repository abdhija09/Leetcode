class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>hash;
        int maxi=0;
        int mini=0;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        
        for(int i=mini;i<=maxi;i++){
        if(hash[i]!=0){
            while(hash[i]>2){
                auto it = find(nums.begin(), nums.end(), i);
                if (it != nums.end()) {
                nums.erase(it);}
                hash[i]--;
            }
            }
            else continue;
        }
        return nums.size();
    }
};