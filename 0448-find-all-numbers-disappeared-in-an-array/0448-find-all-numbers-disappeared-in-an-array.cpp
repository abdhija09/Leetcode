class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> c;
        int n = nums.size();
        int k = *max_element(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        int i = 1;
        int j = 0;

        for(int x = 0; x < n; x++) {
            
            if(j < nums.size() && nums[j] == i) {
                j++;
            } else {
                c.push_back(i);
            }

            i++;
        }

        return c;
    }
};