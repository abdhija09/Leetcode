class Solution { 
public: 
    vector<string> topKFrequent(vector<string>& words, int k) { 
        sort(words.begin(),words.end()); 
        int n=words.size(); 
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq; 
        int cnt=1; 
        for(int i=0;i<n-1;i++){ 
            if(words[i]==words[i+1]){ 
                cnt++; 
            } 
            else{ 
                pq.push({-cnt,words[i]}); 
                cnt=1; 
            } 
        } 
        pq.push({-cnt,words[n-1]}); 

        vector<string>ans; 
        while(k>0 && !pq.empty()){ 
            auto it=pq.top(); 
            string s=it.second; 
            pq.pop(); 
            ans.push_back(s); 
            k--; 
        } 
        return ans; 
    } 
};