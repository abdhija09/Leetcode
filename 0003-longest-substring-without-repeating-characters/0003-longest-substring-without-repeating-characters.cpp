class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 1;
        int n = s.size();
        if(n == 0) return 0;
        int maxlen = 1;
        vector<int> ans;
        ans.push_back(s[l]);

        while(r < n) {
            if(find(ans.begin(), ans.end(), s[r]) != ans.end()) {
                maxlen = max(maxlen, r - l);
                ans.erase(find(ans.begin(), ans.end(), s[l]));
                l++;
            } else {
                ans.push_back(s[r]);
                maxlen = max(maxlen, r - l + 1);
                r++;
            }
        }
        return maxlen;
    }
};