class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int hashh[26] = {0};
        int count = 0;

        for (int i = 0; i < chars.size(); i++) {
            hashh[chars[i] - 'a']++;
        }

        for (int i = 0; i < words.size(); i++) {
            int hash[26] = {0};

            for (char it : words[i]) {
                hash[it - 'a']++;
            }

            int j;
            for (j = 0; j < 26; j++) {
                if (hash[j] > hashh[j]) break;
            }

            if (j == 26) count += words[i].size();  
        }

        return count;
    }
};