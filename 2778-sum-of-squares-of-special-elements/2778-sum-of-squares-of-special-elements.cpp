class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sumsq=0;
        vector<int>c;
        int n=nums.size();
        for(int i=1;i<=nums.size();i++){
        if(n%i==0) {
               c.emplace_back(nums[i-1]);
        }
        
            
        }
        if(c.size()==0) return 0;
        for(int i=0;i<c.size();i++){
            sumsq+=c[i]*c[i];
        }
        return sumsq;
    
    }
};