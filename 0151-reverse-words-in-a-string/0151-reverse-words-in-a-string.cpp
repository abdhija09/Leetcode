class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word) {       
            words.push_back(word);
        }

        reverse(words.begin(), words.end());
        string ans = "";
        for(int i = 0; i < words.size(); i++) {
            if(i != 0) ans += " ";
            ans += words[i];
        }

        return ans;
    }
};