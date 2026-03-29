class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = -1, ans = 0;
        int n = s.size();
        vector<int> c;

        for(int i = 0; i < n; i++){
            if(s[i] == ' ') c.push_back(i);
        }
        int i = n - 1;
        while(i >= 0 && s[i] == ' ') {
            i--;
        }
        for(int j = 0; j < c.size(); j++){
            if(c[j] < i) count = c[j];
        }

        for(int k = count + 1; k <= i; k++){
            ans++;
        }

        return ans;
    }
};