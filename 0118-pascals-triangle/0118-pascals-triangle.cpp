class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> t;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            int num = 1;

            for (int j = 0; j <= i; j++) {
                row.push_back(num);
                num = num * (i - j) / (j + 1);
            }

            t.push_back(row);
        }

        return t;
    }
};
