class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for (int i = 0; i < dictionary.size(); i++) {
            string x = dictionary[i];
            int l = 0, r = 0;
            while (l<s.size() && r<x.size()) {
                if (s[l]==x[r]) {
                    r++;
                }
                l++;
            }
            if (r==x.size()) {
                if (x.size() >ans.size() ||(x.size()==ans.size() && x< ans)) {
                    ans =x;
                }
            }
        }
        return ans;
    }
};