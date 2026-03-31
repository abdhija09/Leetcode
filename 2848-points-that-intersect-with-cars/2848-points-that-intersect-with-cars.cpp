class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans=0;
        vector<int>c;
       for(int i=0;i<nums.size();i++){
        int k=nums[i].size();
        int n=nums[i][0],m=0;
        while(n<=nums[i][k-1]){
           c.push_back(nums[i][0] +m);
           n++;
           m++;
        }
       } 
       sort(c.begin(), c.end());
     c.erase(std::unique(c.begin(), c.end()), c.end());
     ans=c.size();
     return ans;
    }
};