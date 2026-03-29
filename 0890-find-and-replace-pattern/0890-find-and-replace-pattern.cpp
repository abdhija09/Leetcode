class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;

        for (const string& word : words) {
            if (word.size() != pattern.size()) continue;

            map<char, char> p_to_w; // pattern char → word char
            map<char, char> w_to_p; // word char → pattern char
            bool match = true;

            for (int i = 0; i < pattern.size(); i++) {
                char p = pattern[i], w = word[i];

                if (p_to_w.count(p) && p_to_w[p] != w) { match = false; break; }
                if (w_to_p.count(w) && w_to_p[w] != p) { match = false; break; }

                p_to_w[p] = w;
                w_to_p[w] = p;
            }

            if (match) result.push_back(word);
        }

        return result;
    }
};