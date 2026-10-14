class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int n = alice.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({alice[i] + bob[i], i});
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        int aliceScore = 0, bobScore = 0;
        for (int i = 0; i < n; i++) {
            if(i%2 == 0){
                aliceScore += alice[vec[i].second];
            }
            else{
                bobScore += bob[vec[i].second];
            }
        }
        if (aliceScore > bobScore)
            return 1;
        if (aliceScore < bobScore)
            return -1;

        return 0;
    }
};