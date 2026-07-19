class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, bool> vis;

        for(char ch : s)
            freq[ch]++;

        string ans = "";

        for(char ch : s) {
            freq[ch]--;

            if(vis[ch]) continue;

            while(!ans.empty() &&
                  ans.back() > ch &&
                  freq[ans.back()] > 0) {
                vis[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            vis[ch] = true;
        }
        return ans;
    }
};