class Solution {
public:
    vector<vector<pair<long long,long long>>> memo;
    vector<bool> computed[4]; // not used, replaced below

    pair<long long,long long> f(vector<int>&nums,int ind,int count){
       if(count==0){
          return {1,1};
       }
       if(ind>=(int)nums.size() || (int)nums.size()-ind<count){
          return {LLONG_MIN,LLONG_MAX};
       }
       if(memo[ind][count].first!=LLONG_MIN || memo[ind][count].second!=LLONG_MAX){
          return memo[ind][count];
       }

       auto rest=f(nums,ind+1,count-1);
       long long takeMax=LLONG_MIN, takeMin=LLONG_MAX;
       if(rest.first!=LLONG_MIN){
          long long c1=(long long)nums[ind]*rest.first;
          long long c2=(long long)nums[ind]*rest.second;
          takeMax=max(c1,c2);
          takeMin=min(c1,c2);
       }
       auto skip=f(nums,ind+1,count);
       long long finalMax=max(takeMax,skip.first);
       long long finalMin=min(takeMin,skip.second);

       memo[ind][count]={finalMax,finalMin};
       return memo[ind][count];
    }
    int maximumProduct(vector<int>& nums) {
      int n=nums.size();
      memo.assign(n+1, vector<pair<long long,long long>>(4, {LLONG_MIN, LLONG_MAX}));
      return (int)f(nums,0,3).first;
    }
};