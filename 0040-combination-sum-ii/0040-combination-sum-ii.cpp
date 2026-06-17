class Solution {
public:
    void solve(int ind, vector<vector<int>>& ans, vector<int>& a, vector<int>& candidate, int target) {
        if (target == 0) {
            ans.push_back(a);
            return;
        }
        if (target < 0 || ind == candidate.size()) return;

        for (int i = ind; i < candidate.size(); i++) {
            if (i > ind && candidate[i] == candidate[i - 1]) continue;
            if (candidate[i] > target) break;
            a.push_back(candidate[i]);
            solve(i + 1, ans, a, candidate, target - candidate[i]);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        sort(candidates.begin(), candidates.end());
        solve(0, ans, a, candidates, target);
        return ans;
    }
};