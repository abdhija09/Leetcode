class Solution {
public:
    int priority(const string& b) {
        if (b == "electronics") return 0;
        if (b == "grocery")     return 1;
        if (b == "pharmacy")    return 2;
        if (b == "restaurant")  return 3;
        return 4;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();
        vector<pair<string, string>> temp;

        for (int i = 0; i < n; i++) {
            if (isActive[i] &&
                (businessLine[i] == "electronics" ||
                 businessLine[i] == "grocery" ||
                 businessLine[i] == "pharmacy" ||
                 businessLine[i] == "restaurant")) {

                if (!code[i].empty() &&
                    all_of(code[i].begin(), code[i].end(),
                           [](char c) {
                               return isalnum(c) || c == '_';
                           })) {

                    temp.push_back({businessLine[i], code[i]});
                }
            }
        }

        sort(temp.begin(), temp.end(),
             [&](const auto& a, const auto& b) {
                 int pa = priority(a.first);
                 int pb = priority(b.first);
                 if (pa != pb)
                     return pa < pb;         
                 return a.second < b.second;   
             });

        vector<string> result;
        for (auto& p : temp)
            result.push_back(p.second);

        return result;
    }
};
