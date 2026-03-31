class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int hash[26]={0};
        bool ok=true;
        int n=words.size();
        for(int i=0;i<words.size();i++){
            for(char it:words[i]){
                hash[it-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(hash[i]%n!=0){
                ok=false;
                return ok;
            }
            else continue;
        }
 return ok;
        }
       
    };