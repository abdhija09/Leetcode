class Solution {
public:
    int beautySum(string s) {
        vector<string>c;
        int count=0;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<=s.size();j++){
              c.push_back(s.substr(i, j-i)); 
            }
        }
        for(int i = 0; i < c.size(); i++) {
    int hash[26] = {0};

    for(auto it : c[i]) {
        hash[it-'a']++;  
    }

   int maxi = 0;  
   int mini = INT_MAX;

    for(int j = 0; j < 26; j++) {
        if(hash[j] != 0) {
            maxi = max(maxi, hash[j]); 
            mini = min(mini, hash[j]); 
        }
    }
    if(maxi > 0) {         
    int diff=maxi-mini;
    count+=diff;
    }
 
    }
    return count;
    }
};