class Solution {
public:
    string s="";
    string convert2binary(int n){
     while(n!=1){
            if(n%2==1)s+="1";
            else s+="0";
            n=n/2;
        }
        s+="1";
        return s;
    }
    int hammingWeight(int n) {
        convert2binary(n);
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') count++;
        }
        return count;
    }
};