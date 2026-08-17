class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        int drow[] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1,-1, 1,-1, 0, 1};

        int cnt = 0;

        while (!q.empty()) {
            int sz = q.size();
            cnt++;
            for (int k = 0; k < sz; k++) {
                pair<int,int> node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                if (r == n-1 && c == m-1) return cnt;
                for (int i = 0; i < 8; i++) {
                    int dr = r + drow[i];
                    int dc = c + dcol[i];
                    if (dr >= 0 && dr < n && dc >= 0 && dc < m &&
                        grid[dr][dc] == 0 && !vis[dr][dc]) {
                        vis[dr][dc] = 1;
                        q.push({dr, dc});
                    }
                }
            }
        }
        return -1;
    }
};