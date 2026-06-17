class Solution {
public:
    void solve(int ind,vector<vector<int>>& subset,vector<int>& nums,vector<int>&a){
       subset.push_back(a);
        for(int i=ind;i<nums.size();i++){
        if(i>ind && nums[i]==nums[i-1])continue;
        a.push_back(nums[i]);
        solve(i+1,subset,nums,a);
        a.pop_back();
        }  
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>a;
        sort(nums.begin(),nums.end());
        solve(0,subset,nums,a);
        return subset;
    }
};