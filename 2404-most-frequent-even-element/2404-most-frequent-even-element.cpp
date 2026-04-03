class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int hash[100001] = {0};  

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                hash[nums[i]]++;
            }
        }

        int ans = -1, maxi = 0;

        for (int i = 0; i <= 100000; i += 2) { 
            if (hash[i] > maxi) {
                maxi = hash[i];
                ans = i;
            }
        }

        return ans;
    }
};