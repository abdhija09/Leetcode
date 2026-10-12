class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         for(int i=0;i<n;){
            int cnt=1;
            while(i+1<n && nums[i]==nums[i+1]){
                cnt++;
                i++;
            }
            pq.push({nums[i],cnt});
            i++;
        }
        int cnt=1;
        vector<int>ans;
       vector<pair<int,int>> temp;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.first);
            it.second--;
            if(it.second>0){
                temp.push_back({it.first,it.second});
            }
        }
       
while(!temp.empty()){
    vector<pair<int,int>> next;
    for(auto it : temp){
        ans.push_back(it.first);
        it.second--;
        if(it.second > 0){
            next.push_back(it);
        }
    }
    temp = next;
}
return ans;
    }
};