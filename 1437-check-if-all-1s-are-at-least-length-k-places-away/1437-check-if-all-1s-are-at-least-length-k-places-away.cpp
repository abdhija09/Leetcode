class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> c;
        int count = 0;
        bool ok = true;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                int n = 1;
                count = 0;
                while ((i + n) < nums.size() && nums[i + n] == 0) {
                    count++;
                    n++;
                }

                if ((i + n) < nums.size() && nums[i + n] == 1) {
                    c.push_back(count);
                }
            }
        }

        for (int i = 0; i < c.size(); i++) {
            if (c[i] < k) {
                ok = false;
                break;
            }
        }

        return ok;
    }
};