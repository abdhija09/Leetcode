class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         bool ok=false;
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int i = mid / m;
            int j = mid % m;
            if(matrix[i][j]>target){
               high=mid-1;
            }
            else if(matrix[i][j]==target){
                 ok=true;
                 return ok;}
            else low=mid+1;

}
return ok;
    }  
};