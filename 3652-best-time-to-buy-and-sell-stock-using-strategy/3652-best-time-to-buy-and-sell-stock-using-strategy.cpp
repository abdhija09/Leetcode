class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        int n = p.size(), h = k / 2;
        long long b = 0;

        for (int i = 0; i < n; i++)
            b += 1LL * s[i] * p[i];

        long long d = 0;
        for (int i = 0; i < h; i++)
            d -= 1LL * s[i] * p[i];
        for (int i = h; i < k; i++)
            d += 1LL * (1 - s[i]) * p[i];

        long long mx = max(0LL, d);

        for (int l = 1; l + k <= n; l++) {
            d += 1LL * s[l - 1] * p[l - 1];
            d -= 1LL * (1 - s[l + h - 1]) * p[l + h - 1];
            d -= 1LL * s[l + h - 1] * p[l + h - 1];
            d += 1LL * (1 - s[l + k - 1]) * p[l + k - 1];
            mx = max(mx, d);
        }

        return b + mx;
    }
};
