class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;

        for(int x : nums)
            v.push_back(to_string(x));

        sort(v.begin(), v.end(), [](string a, string b) {
            return a + b > b + a;
        });

        string ans = "";

        for(string x : v)
            ans += x;

        if(ans[0] == '0')
            return "0";

        return ans;
    }
};