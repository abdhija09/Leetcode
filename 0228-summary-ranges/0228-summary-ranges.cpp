class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> temp;
        vector<string> result;
          if(n==0){
            return result;
        }
         if(n == 1) {                                  
            result.push_back(to_string(nums[0]));
            return result;
        }
        int maxi = nums[0], mini = nums[0]; 
        int k = 0;
      
        for(int i = 0; i < n - 1; i++) {
            if(nums[i+1] == nums[i] + 1) {  
                maxi = nums[i+1];
            }
            else {
              
                temp.push_back({mini, maxi});  
                k++;
                mini = nums[i+1];  
                maxi = nums[i+1];
            }
        }
        temp.push_back({mini, maxi});  

   
        for(auto& v : temp) {
            if(v[0] == v[1])
                result.push_back(to_string(v[0]));
            else
                result.push_back(to_string(v[0]) + "->" + to_string(v[1]));
        }

        return result;
    }
};