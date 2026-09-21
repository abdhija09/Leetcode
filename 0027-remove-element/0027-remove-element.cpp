class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int m=nums.size();
        sort(nums.begin(),nums.end());
        int n=count(nums.begin(),nums.end(),val);
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return m-n;
    }
};