class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busyRooms;

        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) freeRooms.push(i);

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];

            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end, room});
                count[room]++;
            } else {
                auto [time, room] = busyRooms.top();
                busyRooms.pop();
                busyRooms.push({time + (end - start), room});
                count[room]++;
            }
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};
