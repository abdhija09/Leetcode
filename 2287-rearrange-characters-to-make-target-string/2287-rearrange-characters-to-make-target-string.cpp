class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int hashh[26]={0};
        int hash[26]={0};
        int maxi=INT_MAX;;
        for(int i=0;i<target.size();i++){
            hashh[target[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if(hashh[j]!=0){
             int n=hash[j]/hashh[j];
             maxi=min(maxi,n);
            }
        }
        return maxi;
    }
};