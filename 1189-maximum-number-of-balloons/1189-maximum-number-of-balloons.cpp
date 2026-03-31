class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int hashh[26]={0};
        int hash[26]={0};
        string s;
        s="balloon";
        int maxi=INT_MAX; 
        if(text.size()<7) return 0;
        for(int i=0;i<s.size();i++){
            hashh[s[i]-'a']++;
        }
        for(int i=0;i<text.size();i++){
            hash[text[i]-'a']++;
        }
      for (int j = 0; j < 26; j++) {
       if (hashh[j] > 0) {
        int n = hash[j] / hashh[j];
        if (n == 0) { maxi = 0;
        return maxi; }  
        maxi = min(maxi, n); 
    }
}
        return maxi;
    
    }
};