class Solution {
public:
    bool isPalindrome(string s) {
        bool ok = true;
        string q;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
                q += s[i];
            }
        }

        int m = q.size();

        if (m == 0) return ok;

        for (int i = 0; i < m / 2; i++) {
            if (q[i] != q[m - i - 1]) {
                ok = false;
                return ok;
            }
        }

        return ok;
    }
};