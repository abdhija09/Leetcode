class Solution {

public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ok;
        long long num=0;
        for(int i=0;i<nums.size();i++){
            num=(num*2+nums[i])%5;  
            ok.push_back(num==0);
        }
        return ok;
    }
};
   