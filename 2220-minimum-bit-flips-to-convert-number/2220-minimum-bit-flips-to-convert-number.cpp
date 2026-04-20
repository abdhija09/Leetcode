class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;
        int count=0;
        while(x>1){
             if(x&1){
                count++;
             }
             x>>=1;
        }
        if(x==1) count++;
        return count;
    }
};