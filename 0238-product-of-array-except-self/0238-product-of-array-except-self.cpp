class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> c;
        int product = 1;
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) product *= nums[i];
            else zeroCount++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 1) {
                c.push_back(0);        
            } else if (zeroCount == 1) {
                if (nums[i] == 0)
                    c.push_back(product); 
                else
                    c.push_back(0);  
            } else {
                c.push_back(product / nums[i]);
            }
        }

        return c;
    }
};