class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
         vector<int>mpp(1001,0),hp(1001,0);
        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            hp[nums2[i]]++;
        }
        for(int i=0;i<max(mpp.size(),hp.size());i++){
            while(mpp[i]>0 && hp[i]>0){
               ans.push_back(i);
               mpp[i]--;
               hp[i]--;
            }
        }

   return ans;
    }
};