class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;       
        int n = s.size();                   
        int l = 0, r = 0, count = 0;
        vector<char> ans;                  
        while (r < n) {
            mpp[s[r]]++;                    
            if (find(ans.begin(), ans.end(), s[r]) == ans.end()) {
                ans.push_back(s[r]);
            }
            while (ans.size() == 3) {         
                count += (n - r);               
                mpp[s[l]]--;
                if (mpp[s[l]] == 0) { 
                    ans.erase(find(ans.begin(), ans.end(), s[l]));
                }
                l++;
            }
            r++;
        }

        return count;
    }
};