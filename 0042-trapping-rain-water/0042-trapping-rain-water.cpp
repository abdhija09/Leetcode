class Solution {
public:
    vector<int> findrightmax(vector<int>& arr){
        int n=arr.size();
        vector<int>suffix(n);
        suffix[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],arr[i]);
        }
        return suffix;
    }

    vector<int> findleftmax(vector<int>& arr){
        int n=arr.size();
        vector<int>prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
               prefix[i]=max(prefix[i-1],arr[i]);
        }
        return prefix;
    }

    int trap(vector<int>& height){
        int sum=0;
        vector<int> leftmax=findleftmax(height);
        vector<int> rightmax=findrightmax(height);
        for(int i=0;i<height.size();i++){
            int water=min(leftmax[i],rightmax[i])-height[i];
            if(water>0) sum+=water;
        }
        return sum;
    }
};