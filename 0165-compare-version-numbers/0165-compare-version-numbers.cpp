class Solution {
public:
    int compareVersion(string version1, string version2) {

        int x = stoi(version1);
        int y = stoi(version2);
        string s1 = "", s2 = "";

        if (x > y) return 1;
        else if (x < y) return -1;
        else {
            int r = 0, l = 0;
            while (r < version1.size() && l < version2.size() &&
                   version1[r] == version2[l] && version1[r] != '.') {
                r++;
                l++;
            }
            while (r < version1.size() && version1[r] == '0') r++;
            while (l < version2.size() && version2[l] == '0') l++;
            while (r < version1.size() || l < version2.size()) {

                if (r < version1.size() && version1[r] == '.') {
                    if (!s1.empty()) s1 = "";
                    r++;
                    while (r < version1.size() && version1[r] == '0') r++;
                }
                else if (r >= version1.size()) {
                    s1 = "";
                }

                if (l < version2.size() && version2[l] == '.') {
                    if (!s2.empty()) s2 = "";
                    l++;
                    while (l < version2.size() && version2[l] == '0') l++;
                }
                else if (l >= version2.size()) {
                    s2 = "";
                }

                while (r < version1.size() && version1[r] != '.') s1 += version1[r++];
                while (l < version2.size() && version2[l] != '.') s2 += version2[l++];

                int a = s1.empty() ? 0 : stoi(s1);
                int b = s2.empty() ? 0 : stoi(s2);
                if (a > b) return 1;
                if (a < b) return -1;
            }
        }
        return 0;
    }
};