class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        vector<int> c(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            int n=stoi(s);
            c.push_back(n);
        }
        sort(c.begin(),c.end());
        c.erase(unique(c.begin(),c.end()),c.end());
     int x=c.size();
     return x;
    }
};