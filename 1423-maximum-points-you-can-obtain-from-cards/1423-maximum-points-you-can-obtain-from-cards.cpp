class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,sum=0, maxsum=0;;
    for(int i=0;i<k;i++){
       sum+=cardPoints[i];
     } 
     lsum=sum;
     maxsum=lsum;
     int n=cardPoints.size();
     int rindx=n-1;
     
     for(int i=k-1;i>=0;i--){
        lsum=lsum-cardPoints[i];
        rsum+=cardPoints[rindx];
        rindx--;
    maxsum=max(maxsum,lsum+rsum);
     }
     return maxsum;
    }
};