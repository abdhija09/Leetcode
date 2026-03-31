class Solution {
public:
    bool canConstruct(string ransomnote, string magazine) {
        bool ok =false;  
        int hash[26]={0};
        int hashh[26]={0};
        if(ransomnote.size()>magazine.size()){
            return ok;
        }
        for(int i=0;i<magazine.size();i++){
            hash[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomnote.size();i++){
            hashh[ransomnote[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] < hashh[i]) {
                ok = false;
                return ok;
            }
        }
        ok = true;
        return ok;
        
    }
};