class Solution {
public:
    bool isSameAfterReversals(int num) {
        bool ok=true;
       string s=to_string(num);
       int n=s.size();
       if(s[n-1]=='0' && n>1){
        ok =false;
        return ok;
       }
       return ok;
    }
};