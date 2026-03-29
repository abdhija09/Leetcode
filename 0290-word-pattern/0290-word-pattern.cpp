
class Solution {
public:
bool wordPattern(string pattern, string s) {
vector<string> words;
string word = "";
  map<char,string>p_to_s;
        map<string,char>s_to_p;
       bool ok=true;
for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
        words.push_back(word);
        word = "";
    } else {
        word += s[i];
    }
}
words.push_back(word);

if(words.size()!=pattern.size()){
    ok=false;
    return ok;
}
      
        for(int i=0;i<pattern.size();i++){
            if(p_to_s.count(pattern[i])){
                 if (p_to_s[pattern[i]] != words[i]) return false;
            }
            else{
                p_to_s[pattern[i]]=words[i];
            }
            if(s_to_p.count(words[i])){
                  if (s_to_p[words[i]] != pattern[i]) return false;
            }
            else{
                s_to_p[words[i]]= pattern[i];
            }

        }
        return ok;
        
    }
};