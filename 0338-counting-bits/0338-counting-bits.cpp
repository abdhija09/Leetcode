class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>c;
        
        for(int i=0;i<=n;i++){
            int count=0;
            int num=i;
        while(num){
           if(num&1) count++;
           num>>=1;
        }
        c.push_back(count);
    }
    return c;
    }
};