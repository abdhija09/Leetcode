class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end()); 
        set<vector<int>>st; 
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            set<int>hashset;  
            for(int j=i+1;j<n;j++){
              int th=-(nums[i]+nums[j]);
              if(hashset.find(th)!=hashset.end()){
                vector<int>temp={nums[i],nums[j],th};
                sort(temp.begin(),temp.end());
                st.insert(temp);
              }
              hashset.insert(nums[j]);
            }

        }
        vector<vector<int>> c(st.begin(),st.end());
        return c;
    }
};