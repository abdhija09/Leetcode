class Solution {
public:
    vector<int> pse(vector<int>& heights){ 
        int n=heights.size();
        vector<int> left(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return left;
    }

    vector<int> nse(vector<int>& heights){  
        int n=heights.size();
        vector<int> right(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            right[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return right;
    }

    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        vector<int> left=pse(heights); 
        vector<int> right=nse(heights); 
        int maxArea=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            maxArea=max(maxArea,heights[i]*width);
        }
        return maxArea;
    }
};