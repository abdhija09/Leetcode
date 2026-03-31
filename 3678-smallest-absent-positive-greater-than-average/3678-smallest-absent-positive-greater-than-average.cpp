class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum,avg;
        int ans;
        int n=nums.size();
      
    for(int i=0;i<nums.size();i++){
            sum+= nums[i];
        }
    if(nums[0]<0 && n==1){
            ans=1;
            return ans;
        }
    
    avg=sum/n;
    if(avg>0 && avg<1) avg=1;
    if(avg>=0) avg=avg+1;;
      sort(nums.begin(), nums.end());
        nums.erase(remove_if(nums.begin(), nums.end(), [](int x) {
            return x <= 0;
        }), nums.end());
        if(nums.size()==0){
            ans=1;
            return ans;
        }
        for(int i=0;i<nums.size();i++){
        if(avg<0 ){
            avg=1;
        }
                if(avg==nums[i]) avg++;
            
        }
        ans=avg;
        return ans;
    }
};