class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int ans;
       int k=n+1;
       sort(nums.begin(),nums.end());
        if(n==1 &&nums[0]==0){ans=1; return ans;}
        while (k>0){
        int j=0;
        for(int i=0;i<nums.size();i++ ){
                     if(nums[i]==j){ j++;
                     k--;}
                     else {ans=j;
                     return ans;
                     }
        }

       }
       if(nums[n-1]==n-1) ans=n;
       return ans;
    }
};