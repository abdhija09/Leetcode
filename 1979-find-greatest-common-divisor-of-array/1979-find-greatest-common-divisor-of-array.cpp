class Solution {
public:
    int findGCD(vector<int>& nums) {
        int gd=gcd(*max_element(nums.begin(),nums.end()),*min_element(nums.begin(),nums.end()));
        return gd;
    }
};