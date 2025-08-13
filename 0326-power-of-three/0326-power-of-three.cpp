class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double r = log(n) / log(3);
        return fabs(r - round(r)) < 1e-10;
    }
};
