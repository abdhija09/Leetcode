class Solution {
public:
    bool isPowerOfTwo(int n) {
    bool ok=true;
    if (n==1) return ok;
    if(n==0){
        ok=false;
        return ok;
    }
    while(n>1){
        if(n%2==1){
            ok=false;
            break;
        }
        
        n/=2;
    }
   if(n<0) {
    ok=false;
    return ok;
   }
return ok;
    }
};