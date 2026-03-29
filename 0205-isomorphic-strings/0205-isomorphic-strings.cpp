class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, char> s_to_t;
        map<char, char> t_to_s;

        for (int i = 0; i < s.size(); i++) {
            if (s_to_t.count(s[i])) {
                if (s_to_t[s[i]] != t[i]) return false;
            } else {
                s_to_t[s[i]] = t[i];
            }

            if (t_to_s.count(t[i])) {
                if (t_to_s[t[i]] != s[i]) return false;
            } else {
                t_to_s[t[i]] = s[i];
            }
        }

        return true;
    }
};