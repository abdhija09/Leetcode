class Solution {
public:
long long n=1e7;
    bool isPerfectSquare(int num) {
        bool ok =false;
        for(long long i=0;i<=n;i++){
            if(i*i==num){
                 ok=true;
                 return  ok;
        }
      
    }
      return ok;
    }
};