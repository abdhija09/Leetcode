class Solution {
public:
void solve(int ind,int k,int n,vector<vector<int>>& ans,vector<int>& set){
    if(set.size()==k){
        if(n==0){
        sort(set.begin(),set.end());
        ans.push_back(set);
        }
        return;
       
    }
   
    for(int i=ind;i<=9;i++){
    set.push_back(i);
    solve(i+1,k,n-i,ans,set);
    set.pop_back();      
    
}
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>set;
        solve(1,k, n,ans,set);
        sort(ans.begin(),ans.end());
        return ans;
    
}
};