class Solution {
public:
    long long maximumProfit(vector<int>& p, int k) {
        const long long N = -1e18;

        vector<long long> f(k + 1, 0);
        vector<long long> l(k + 1, N);
        vector<long long> s(k + 1, N);

        for (int x : p) {
            for (int i = 0; i <= k; i++) {
                if (i < k) {
                    l[i] = max(l[i], f[i] - x);
                    s[i] = max(s[i], f[i] + x);
                }
                if (i > 0) {
                    f[i] = max(f[i], max(l[i - 1] + x, s[i - 1] - x));
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i <= k; i++) ans = max(ans, f[i]);
        return ans;
    }
};
