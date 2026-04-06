class Solution {
public:
    bool isPowerOfFour(int n) {
    bool ok=true;
    if (n==1) return ok;
    if(n==0){
        ok=false;
        return ok;
    }
    while(n>1){
        if(n%4!=0){
            ok=false;
            break;
        }
        
        n/=4;
    }
   if(n<0) {
    ok=false;
    return ok;
   }
return ok;
    }
};