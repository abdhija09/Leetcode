class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i=0;
        int n=matrix.size();
        vector<int>ans;
        if(n==1) return matrix[0][0];
        while(i<n){
            int j=0,k=n-1;
            while(j<=k){
               ans.push_back(matrix[i][j]);
                if (j != k) {
                    ans.push_back(matrix[i][k]);
                }
            
               j++;
               k--;
            }
            i++;
        }
        if(ans.empty()) return 0;
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};