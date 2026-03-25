class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int ans=nums[0];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }
            else if(count+1>n/2) {ans=nums[i];
            return ans;}
            else {continue;
            count=0;}   
            
            }
            if(count + 1 > n/2) {
            ans = nums[n-1];
        }
            return ans;
        }
        
    };
