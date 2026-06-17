class Solution {
public:
    void solve(int ind,vector<vector<int>>& subset,vector<int>& nums,vector<int>&a){
        if(ind==nums.size()){
            subset.push_back(a);
            return;
        }
        a.push_back(nums[ind]);
        solve(ind+1,subset,nums,a);
        a.pop_back();
        
        solve(ind+1,subset,nums,a);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>a;
        sort(nums.begin(),nums.end());
        solve(0,subset,nums,a);
        sort(subset.begin(),subset.end());
        subset.erase(unique(subset.begin(), subset.end()), subset.end());
        return subset;
    }
};