class Solution {
public:
    bool judgeSquareSum(int c) {
        long long lo = 0, hi = (long long)sqrt((double)c);
        bool ok = false;

        while (lo <= hi) {
            long long sum = lo * lo + hi * hi;
            if (sum == c) {
                ok = true;
                return ok;
            }
            else if (sum < c) lo++;
            else               hi--;
        }
        return ok;
    }
};