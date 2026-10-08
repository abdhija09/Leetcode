class Solution {
public:
    string rle(string s) {
        string n = "";
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty() ||st.top() == s[i]) {
                st.push(s[i]);                
            }
            else {                          
                n += to_string(st.size());  
                n += st.top();    
                while (!st.empty()) st.pop();
                st.push(s[i]);             
            }
        }

        n += to_string(st.size()); 
        n += st.top();
        return n;
    }

    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            ans = rle(ans);
        }
        return ans;
    }
};