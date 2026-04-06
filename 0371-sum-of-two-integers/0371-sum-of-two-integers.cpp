class Solution {
public:
    int getSum(int a, int b) {
        double ans;
        if(a==b){
            ans=2*a;
            return ans;
        }
        double n=pow(2,a)*pow(2,b);
        ans=log2(n);
         return ans; 
    }
};