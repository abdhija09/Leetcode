class Solution {
public:
    int countPrimes(int n) {
       priority_queue<int,vector<int>,greater<int>>pq;
       int ans=2;
      if(ans>=n) return 0;
       pq.push(2);
       while(ans<n-1){
        bool ok=true;
          ans++;
           if(ans%2==0) continue;
           if(ans%2==1){
            for(int i=3;i*i<=ans;i+=2){
             if(ans%i==0){
               ok=false;
               break;
             }
           }
           }
           
           if(ok) {
            pq.push(ans);
           }
       }
       return pq.size();
    }
};