class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        vector<vector<int>> temp; 
        vector<int> ans;         
        
       for(int i = 1; i * i <= area; i++){
        if(area % i == 0){
        int j = area / i;
        temp.push_back({j,i});
        
    }
}
        int mini=INT_MIN;
        int diff = INT_MAX;
        if(temp.size()==1){
           ans = {temp[0][0], temp[0][1]}; 
           return ans;
        }
        for(int i = 0; i < temp.size(); i++){
            if(temp[i][0] >= temp[i][1]){
                if(diff > (temp[i][0] - temp[i][1])){
                    diff = temp[i][0] - temp[i][1];
                    ans = {temp[i][0], temp[i][1]}; 
                }
            }
        }
      
        return ans;
    }
};