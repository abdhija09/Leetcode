class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        
        for(int i=0;i<n;i++){
            stack<int> st;
            for(int j=n-1;j>=i;j--){
                st.push(nums[j]);
            }
            
            stack<int> temp;
            long long mn=INT_MAX;
            long long mx=INT_MIN;
            while(!st.empty()){
                temp.push(st.top());
                mn=min(mn,(long long)st.top());
                mx=max(mx,(long long)st.top());
                st.pop();
                sum+=(mx-mn); 
            }
        }
        return sum;
    }
};