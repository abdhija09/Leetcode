class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int l=0,r=0,maxlen=0,sum=0;
        int n=costs.size();
        sort(costs.begin(),costs.end());
        while(r<n){
            sum+=costs[r];
            while(sum>coins){
                sum-=costs[l];
                l++;
            }
            if(sum<=coins){
            maxlen=max(maxlen,r-l+1);
            r++;
            }
           
        }
        return maxlen;
    }
};