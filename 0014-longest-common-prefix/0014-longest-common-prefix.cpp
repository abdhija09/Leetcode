class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";

        if (strs.size() == 0) return s;

        for (int j = 0; j < strs[0].size(); j++) {
            char ch = strs[0][j];

            for (int i = 0; i < strs.size() - 1; i++) {
                if (j >= strs[i + 1].size() || strs[i][j] != strs[i + 1][j]) {
                    return s;
                }
            }

            s += ch;
        }

        return s;
    }
};