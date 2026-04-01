class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> zeroRows, zeroCols;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.push_back(i); 
                    zeroCols.push_back(j);  
                }
            }
        }

        for (int r : zeroRows)
            for (int j = 0; j < n; j++)
                matrix[r][j] = 0;

        for (int c : zeroCols)
            for (int i = 0; i < m; i++)
                matrix[i][c] = 0;

    return ;            
    }
};