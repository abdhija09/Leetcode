class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int r=0,l=0;
        int n=fruits.size();
        int maxlen=0;
        vector<int> ans;
        ans.push_back(fruits[0]);
        while(r<n){
            while(r<n && ans.size()<=2){
                if(find(ans.begin(),ans.end(),fruits[r])!=ans.end()){
                    maxlen=max(maxlen,r-l+1);
                    r++;
                }
                else if(ans.size()<2){
                    ans.push_back(fruits[r]);
                    maxlen=max(maxlen,r-l+1);
                    r++;
                }
                else{
                    break; 
                }
            }
            if(r>=n) break;
            bool exists=true;
            while(exists){
                bool found=false;
                for(int i=l+1;i<r;i++){
                    if(fruits[i]==fruits[l]){ 
                        found=true; 
                        break; }
                }
                if(found){
                    l++;
                }else{
                    ans.erase(find(ans.begin(),ans.end(),fruits[l]));
                    l++;
                    exists=false;
                }
            }
        }
        return maxlen;
    }
};