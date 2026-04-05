class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;  
        long long c = a / b;     

    
        if(c > INT_MAX) return INT_MAX; 
        if(c < INT_MIN) return INT_MIN; 

        return (int)c;
    }
};