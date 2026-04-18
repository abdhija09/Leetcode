class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       vector<int>c;
       int n=mat.size();
       int m=mat[0].size();
       int low=0,high=m-1;
       while(low<=high){
        int mid=(low+high)/2;
        int row=0;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>mat[row][mid]) row=i;
        }
        
        int left  = (mid-1 >= 0) ? mat[row][mid-1] : INT_MIN;
        int right = (mid+1 < m)  ? mat[row][mid+1] : INT_MIN;
        
        if(mat[row][mid]>left && mat[row][mid]>right){
            c.push_back(row);
            c.push_back(mid);
            return c;
        }
        else if(left > mat[row][mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       } 
       return c;
    }
};