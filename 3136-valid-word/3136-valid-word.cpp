class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool hasV = false;
        bool hasC = false;

        for (char ch : word) {
            if (!isalnum(ch)) return false; // Not a digit or letter

            if (isalpha(ch)) {
                if (isVowel(ch))
                    hasV = true;
                else
                    hasC = true;
            }
        }

        return hasV && hasC;
    }
};