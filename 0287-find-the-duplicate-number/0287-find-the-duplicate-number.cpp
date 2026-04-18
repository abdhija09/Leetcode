class Solution {
public:
   int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
       int duplicate = 0; 
    for (int bit = 0; bit < 32; bit++) {
        int actual = 0, expected = 0;
        for (int i = 1; i <= n; i++) expected += (i >> bit) & 1;
        for (int x : nums) actual  += (x >> bit) & 1;
         if (actual > expected)
            duplicate |= (1 << bit); 
    }
    return duplicate;
} 
};