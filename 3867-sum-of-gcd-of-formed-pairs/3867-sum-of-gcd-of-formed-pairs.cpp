class Solution {
public:

    vector<int> prefix(vector<int>& nums){
        int  n=nums.size();
        vector<int>a;
        int maxi=nums[0];
        a.push_back(maxi);
        for(int i=1;i<n;i++){
           if(nums[i]>maxi){
            maxi=nums[i];
           }
           a.push_back(maxi);
        }
        for(int i=0;i<n;i++){
            a[i]=gcd(a[i],nums[i]);
        }
        return a;

    }
    long long gcdSum(vector<int>& nums) {
        vector<int>hp=prefix(nums);
        int  n=nums.size();
        long long gd=0;
        sort(hp.begin(),hp.end());
       
       while (hp.size() >= 2) {
       gd+= gcd(hp.front(), hp.back());
          hp.pop_back();
           hp.erase(hp.begin());
}
        return gd;
    }
};