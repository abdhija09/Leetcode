class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26]={0};
int ans;
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(hash[s[i]-'a']==1){
                ans=i;
                return i;
            }
        }
        return -1;
    }
};