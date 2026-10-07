class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char>st;
        int i=0,n=s.size();
        while(i<n){
            if(s[i]==' '){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                ans+=' ';
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
         while (!st.empty()) { 
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};