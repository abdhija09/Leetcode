class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float,pair<int,int>>,
vector<pair<float,pair<int,int>>>,
greater<pair<float,pair<int,int>>>> pq;
        int i=0,j=i;
        int n=arr.size();
        while(i<n){
        j=i+1;
        while(j<n){
        float x=(float)arr[i]/arr[j];
        pq.push({x,{arr[i],arr[j]}});
        j++;
        }
        i++;
        
        }
        while(!pq.empty() && k-1>0){
            pq.pop();
            k--;
        }
        vector<int>ans;
        if(!pq.empty()){
        auto it=pq.top();
        pair<int,int>s=it.second;
        ans.push_back(s.first);
        ans.push_back(s.second);
        }
        return ans;
    }
};