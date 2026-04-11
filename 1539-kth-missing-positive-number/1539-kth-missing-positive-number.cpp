class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=*max_element(arr.begin(),arr.end());
        vector<int>hash(100001,0);       
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        vector<int>c;
        for(int i=1;i<=100000;i++){     
            if(hash[i]==0){               
                c.push_back(i);
            }
        }
        int ans=c[k-1];
        return ans;
        }
      
    };