class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int r=n/3;
        vector<int>c;
     
        unordered_map<int, int> hash;
       sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int i=0;i<nums.size();i++){
            if(hash[nums[i]]>r){
                c.push_back(nums[i]);
            }
        }
        return c;
    }
};