class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>c;
        for(int i=0;i<words.size();i++){
            for(char it:words[i]){
                if(it==x){
                    c.push_back(i);
                }
            }
        }
        c.erase(unique(c.begin(),c.end()),c.end());
        return c;
    }
};