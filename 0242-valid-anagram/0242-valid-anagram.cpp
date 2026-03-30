class Solution {
public:
    bool isAnagram(string s, string t) {
        bool ok=true;
        int hash[26]={0};
        int hashh[26]={0};

        if(s.size()!=t.size()){

            ok=false;
            return ok;
        }
        for(int i=0;i<t.size();i++ ){
            hash[t[i]-'a']++;
        }
        for(int i=0;i<s.size();i++ ){
            hashh[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]!=hashh[i]){
                ok=false;
                return ok;
            }
            
        }
        return ok;
    }
};