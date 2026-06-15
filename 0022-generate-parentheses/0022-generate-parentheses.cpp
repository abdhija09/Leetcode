class Solution {
public:

    
    void solve(int open, int close, int n,
               string curr, vector<string>& ans) {

        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            solve(open + 1, close, n,
                  curr + '(', ans);
        }

        if (close < open) {
            solve(open, close + 1, n,
                  curr + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(0, 0, n, "", ans);

        return ans;
    }

};