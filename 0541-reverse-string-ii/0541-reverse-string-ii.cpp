class Solution {
public:
    string reverseStr(string s, int k) {
        stack<char>st;
        int i=0,n=s.size();
        string ans;
        while(i<n){
            int cnt=0;
            while(cnt<k && i<n){
                st.push(s[i]);
                cnt++;
                i++;
            }
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            for(int j=i;j<i+k && j<n&& i<n;j++){
                ans+=s[j];
            }
        i+=k;
        }       
        return ans;
    }
};