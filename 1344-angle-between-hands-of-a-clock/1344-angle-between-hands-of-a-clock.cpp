class Solution {
public:
    double angleClock(int hour, int minutes) {
    int rem=hour%12;
    double x=abs(rem+(minutes/60.0))*30;
    double y = (minutes/5.0) * 30;

    double ans = min(abs(x - y), 360 - abs(x - y));

      return ans;
    }
};