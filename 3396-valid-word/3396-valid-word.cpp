class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word) {
            if (!isalnum(ch)) return false; // Not a digit or letter

            if (isalpha(ch)) {
                if (isVowel(ch))
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
        }

        return hasVowel && hasConsonant;
    }
};
