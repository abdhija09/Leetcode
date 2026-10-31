class Solution {
public:
    vector<string> ans;

    void solve(string &s, int idx, int parts, string curr) {
        if (parts == 4) {
            if (idx == s.size())
                ans.push_back(curr);
            return;
        }
        if (parts > 0)
             curr += ".";
        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string sub = s.substr(idx, len);

            if (len > 1 && sub[0] == '0')
                break;

            if (stoi(sub) > 255)
                break;

            

            solve(s, idx + len, parts + 1, curr + sub);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        if (s.size() < 4 || s.size() > 12)
            return ans;

        solve(s, 0, 0, "");
        return ans;
    }
};