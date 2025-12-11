class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> row, col;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            row[x].push_back(y);
            col[y].push_back(x);
        }

        for (auto &p : row) sort(p.second.begin(), p.second.end());
        for (auto &p : col) sort(p.second.begin(), p.second.end());

        int covered = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto &r = row[x];
            auto &c = col[y];

            int i = lower_bound(r.begin(), r.end(), y) - r.begin();
            int j = lower_bound(c.begin(), c.end(), x) - c.begin();

            bool left  = (i > 0);
            bool right = (i < r.size() - 1);
            bool down  = (j > 0);
            bool up    = (j < c.size() - 1);

            if (left && right && up && down)
                covered++;
        }

        return covered;
    }
};
