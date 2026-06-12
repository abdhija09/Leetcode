class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans="";
        if(num.size()==k){
            ans="0";
            return ans;
        }
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()>num[i]){  
                st.pop();
                k--;
            }
            st.push(num[i]);
        } 
        
        while(k>0){          
            st.pop();
            k--;
        }
        
    

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());  
        int start=0;
        while(start<ans.size()-1 && ans[start]=='0') start++;
        return ans.substr(start);
    }
};