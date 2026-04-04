class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int count = 0;
        set<int> hashset(nums.begin(), nums.end()); 

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[j]-nums[i]==diff) {        
                    int th = nums[j]+diff;
                    if(hashset.find(th)!=hashset.end()) { 
                        count++;
                    }
                }
            }
        }
        return count;
    }
};