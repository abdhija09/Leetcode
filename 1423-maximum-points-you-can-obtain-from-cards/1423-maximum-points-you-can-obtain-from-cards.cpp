class Solution {
public:

    void rl(vector<int>& cardPoints, int idx, int k, int sum, vector<int>& ans){
        ans.push_back(sum);
if(idx == k) return;
        rl(cardPoints, idx + 1, k, sum + cardPoints[idx], ans);
    }
    void ll(vector<int>& cardPoints, int k, int l, int sum, vector<int>& ans){
        int n = cardPoints.size();
        ans.push_back(sum);
        if(l == k) return;

        ll(cardPoints, k, l + 1, sum + cardPoints[n - l - 1], ans);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> ans1;
        rl(cardPoints, 0, k, 0, ans1);
         vector<int> ans2;
        ll(cardPoints, k, 0, 0, ans2);

        int maxi = 0;
        for(int i = 0; i <= k; i++){
            maxi = max(maxi, ans1[i] + ans2[k - i]);
        }

        return maxi;
    }
};