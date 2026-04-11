class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int>ans;
       int n=mountain.size();
       for(int i=0;i<n;i++){
        if(i==0|| i==n-1) continue;
        else{
            if(mountain[i-1]<mountain[i] && mountain[i]>mountain[i+1]){
                ans.push_back(i);
            }
        }
       }
    return ans;
    }
};