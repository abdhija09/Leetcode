class Solution {
public:
    int reverse(int x) {
      string c;
string s = to_string(x);
if (x < 0) c += "-";
        s.erase(remove(s.begin(), s.end(), '-'), s.end());  
        
        for(int i=s.size()-1;i>=0;i--){
            c+=s[i];
        }
        if(s.empty()){
            return 0;
        }

     long long n=stoll(c);
     if (n > INT_MAX) n = 0;
     if (n < INT_MIN) n =0;
     return n;
    }
};