class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        set<pair<int,int>> vis;
        int cnt = 0;
        for (auto& s : stones) {
            pair<int,int> start = {s[0], s[1]};
            if (vis.count(start)) continue;
            cnt++;
            queue<pair<int,int>> q;
            q.push(start);
            vis.insert(start);

            while (!q.empty()) {
                auto it = q.front();
                q.pop();
                int xi = it.first;
                int yi = it.second;
                for (auto& t : stones) {
                    int tx = t[0];
                    int ty = t[1];
                    pair<int,int> p = {tx, ty};

                    if ((xi == tx || yi == ty) && !vis.count(p)) {
                        vis.insert(p);
                        q.push(p);
                    }
                }
            }
        }

        return n - cnt;
    }
};