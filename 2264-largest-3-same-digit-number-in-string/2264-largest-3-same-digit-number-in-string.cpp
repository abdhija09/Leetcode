class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        int maxi = -1;
        int n = num.size();

        for(int i = 0; i < n-2; i++) {
            if(num[i] == num[i+1] && num[i+1] == num[i+2]) { 
                maxi = max(maxi, num[i] - '0');
            }
        }

        if(maxi == -1) return "";  
        s.insert(0, 3, '0' + maxi);

        return s;
    }
};