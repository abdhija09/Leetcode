class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        if(n%2==1){
            int k=(n+1)/2;
            ans=nums1[k-1];
            return ans;
        }
        int j = n/2;
        int k = n/2 - 1;
         ans = (nums1[j] + nums1[k]) / 2.0;
        return ans;
    }
};