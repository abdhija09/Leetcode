class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> hasSecret(n, false);
        hasSecret[0] = hasSecret[firstPerson] = true;

        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;

            while (i < meetings.size() && meetings[i][2] == time) {
                int x = meetings[i][0], y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }

            queue<int> q;
            unordered_set<int> visited;

            for (int p : people) {
                if (hasSecret[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        hasSecret[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (hasSecret[i]) ans.push_back(i);
        }
        return ans;
    }
};
