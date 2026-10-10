class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<long long, pair<int,int>>,
               vector<pair<long long, pair<int,int>>>,
               greater<pair<long long, pair<int,int>>>> pq;
        if (nums1.empty() || nums2.empty() || k <= 0) return {};
        vector<vector<int>> ans;
        set<pair<int,int>> visited;

        int l = 0, r = 0;
        pq.push({(long long)nums1[l] + nums2[r], {l, r}});
        visited.insert({l, r});
        while (ans.size() < k && !pq.empty()) {
            auto it = pq.top();
            pq.pop();
            l = it.second.first;
            r = it.second.second;
            vector<int> x;
            x.push_back(nums1[l]);
            x.push_back(nums2[r]);
            ans.push_back(x);
            if (l + 1 < nums1.size() && !visited.count({l + 1, r})) {
                pq.push({(long long)nums1[l + 1] + nums2[r], {l + 1, r}});
                visited.insert({l + 1, r});
            }
            if (r + 1 < nums2.size() && !visited.count({l, r + 1})) {
                pq.push({(long long)nums1[l] + nums2[r + 1], {l, r + 1}});
                visited.insert({l, r + 1});
            }
        }
        return ans;
    }
};