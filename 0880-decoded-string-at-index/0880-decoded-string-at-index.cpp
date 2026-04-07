class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        long long size = 0;

        for(char it : s){
            if(it >= '0' && it <= '9'){
                size *= (it - '0');
            }
            else{
                size++;
            }
        }

        for(int i = s.size() - 1; i >= 0; i--){
            char it = s[i];

            k %= size;

            if(k == 0 && !(it >= '0' && it <= '9')){
                string ans = "";
                ans += it;
                return ans;
            }

            if(it >= '0' && it <= '9'){
                size /= (it - '0');
            }
            else{
                size--;
            }
        }

        return "";
    }
};