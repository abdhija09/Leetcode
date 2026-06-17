class Solution {
public:
    void solve(int ind, vector<string>& s, string& st, string& digits, 
               vector<string>& mapping) {
        if (ind == digits.size()) {
            if (!st.empty()) s.push_back(st);
            return;
        }

        string letters = mapping[digits[ind] - '0'];
        for (char c : letters) {
            st.push_back(c);
            solve(ind + 1, s, st, digits, mapping);
            st.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> s;
        string st = "";
        vector<string> mapping = {
            "",     
            "",     
            "abc",  
            "def",  
            "ghi",            
            "jkl",  
            "mno",  
            "pqrs",
            "tuv",  
            "wxyz"  
        };
        if (digits.empty()) return s;
        solve(0, s, st, digits, mapping);
        return s;
    }
};