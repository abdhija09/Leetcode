class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            int ta = stoi(a[1]), tb = stoi(b[1]);
            return ta == tb ? a[0] < b[0] : ta < tb;
        });

        vector<int> mentions(numberOfUsers, 0);
        unordered_set<int> online, offline;
        for (int i = 0; i < numberOfUsers; i++) online.insert(i);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int i = 0, n = events.size();
        while (i < n) {
            int t = stoi(events[i][1]);

            while (!pq.empty() && pq.top().first <= t) {
                int uid = pq.top().second;
                pq.pop();
                offline.erase(uid);
                online.insert(uid);
            }

            int j = i;
            while (j < n && stoi(events[j][1]) == t) j++;

            for (int k = i; k < j; k++) {
                if (events[k][0] == "OFFLINE") {
                    int uid = stoi(events[k][2]);
                    if (online.count(uid)) {
                        online.erase(uid);
                        offline.insert(uid);
                        pq.push({t + 60, uid});
                    }
                }
            }

            for (int k = i; k < j; k++) {
                if (events[k][0] == "MESSAGE") {
                    string s = events[k][2];
                    if (s == "ALL") {
                        for (int x = 0; x < numberOfUsers; x++) mentions[x]++;
                    } else if (s == "HERE") {
                        for (int uid : online) mentions[uid]++;
                    } else {
                        stringstream ss(s);
                        string tok;
                        while (ss >> tok) {
                            if (tok.rfind("id", 0) == 0) {
                                int uid = stoi(tok.substr(2));
                                mentions[uid]++;
                            }
                        }
                    }
                }
            }

            i = j;
        }

        return mentions;
    }
};
