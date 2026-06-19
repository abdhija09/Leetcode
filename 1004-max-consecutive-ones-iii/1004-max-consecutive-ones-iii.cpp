class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        int maxlen=0;
        int zeros=0;
        while(r<n){

            if(nums[r]==0){
                zeros++;
            }
            if(zeros<=k){
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            else{
                if(nums[l]==0){
                    zeros--;
                }
                l++;
                r++;
            }

        }
        return maxlen;
    }
};  