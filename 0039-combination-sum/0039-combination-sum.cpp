class Solution {
public:
   void solve(int ind,vector<vector<int>>& ans,vector<int>& a,vector<int>& candidate,int target){
    int n=candidate.size();
    if(ind==n){
        if(target==0){
            ans.push_back(a);
        }
        return;
    }
    if(candidate[ind]<=target){
        a.push_back(candidate[ind]);
        solve(ind,ans,a,candidate,target-candidate[ind]);
        a.pop_back();
    }
    solve(ind+1,ans,a,candidate,target);
   
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>a;
        solve(0,ans,a,candidates,target);
        return ans;
    }
};