class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count++;

        }
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        int k=nums.size();
        for(int i=k;i<n;i++ ){
            nums.push_back(0);
        }
        return;
    }
};