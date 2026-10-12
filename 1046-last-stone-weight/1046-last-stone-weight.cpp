class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1) return stones[0];
        sort(stones.begin(),stones.end());
        while(n>=2){
        if(stones[n-2]!=stones[n-1]){
          stones[n-2]=stones[n-1]-stones[n-2];
           stones.erase(stones.end() - 1, stones.end());
          n--;
          sort(stones.begin(),stones.end());
        }
        else if(stones[n-2]==stones[n-1]){
             stones.erase(stones.end() - 2, stones.end());
            n-=2;
           
        }
    }   
    if(!stones.empty())return stones[0];
    return 0;
    }
};