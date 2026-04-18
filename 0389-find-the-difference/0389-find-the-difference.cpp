class Solution {
public:
    char findTheDifference(string s, string t) {
       
    char c = 0;
    for (char ch : s) c ^= ch;
    for (char ch : t) c ^= ch;
    return c;
}
    
};