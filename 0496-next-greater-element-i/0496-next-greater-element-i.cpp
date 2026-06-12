class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    int n=nums1.size();
    
    for(int i=0;i<n;i++){
        stack<int> l;
        for(int j=0;j<nums2.size();j++){
            l.push(nums2[j]);
        }
        
        bool found=false;
        bool greater=false;
        stack<int> temp;
        while(!l.empty()){
            if(l.top()==nums1[i]){
                found=true;
                if(!temp.empty()&& temp.top()>=nums1[i]){
                    ans.push_back(temp.top());  
                }else{
                    ans.push_back(-1);          
                }
                break;
            }
            temp.push(l.top());  
            l.pop();
        }
    }
    return ans;
}
};