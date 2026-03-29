class Solution {
public:
    int romanToInt(string s) {
        int count = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i]=='I') {
                if(i+1 < s.size() && (s[i+1]=='V' || s[i+1]=='X'))
                    count -= 1;
                else count += 1;
            }

            if(s[i]=='X') {
                if(i+1 < s.size() && (s[i+1]=='L' || s[i+1]=='C'))
                    count -= 10;
                else count += 10;
            }

            if(s[i]=='C') {
                if(i+1 < s.size() && (s[i+1]=='D' || s[i+1]=='M'))
                    count -= 100;
                else count += 100;
            }

            if(s[i]=='V') count += 5;
            if(s[i]=='L') count += 50;
            if(s[i]=='D') count += 500;
            if(s[i]=='M') count += 1000;
        }

        return count;
    }
};