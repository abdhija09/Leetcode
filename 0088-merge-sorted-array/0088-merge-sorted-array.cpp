class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        unordered_map<int,int> hash;
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < m; i++) {
            hash[nums1[i]]++;
            maxi = max(maxi, nums1[i]);
            mini = min(mini, nums1[i]);
        }
        for (int j = 0; j < n; j++) {
            hash[nums2[j]]++;
            maxi = max(maxi, nums2[j]);
            mini = min(mini, nums2[j]);
        }
        int k = 0;
        for (long long i = mini; i <= maxi; i++) {  
            if (hash.find(i) != hash.end()) {
                while (hash[i] > 0) {
                    nums1[k++] = i;
                    hash[i]--;
                }
            }
        }
    }
};