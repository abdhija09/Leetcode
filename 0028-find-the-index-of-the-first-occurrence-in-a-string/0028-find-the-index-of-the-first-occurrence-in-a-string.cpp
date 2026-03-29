class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();

        int ans;
        bool ok = false;

        for(int j = 0; j <= m - n; j++) {

            int i = 0;

            while(i < n && needle[i] == haystack[j + i]) {
                i++;
            }

            if(i == n) {
                ok = true;
                ans = j;
                return ans;
            }
        }

        return -1;
    }
};