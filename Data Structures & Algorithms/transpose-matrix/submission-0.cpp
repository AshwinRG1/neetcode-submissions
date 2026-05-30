class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();       // Number of rows in original
        int n = matrix[0].size();    // Number of columns in original

        // Initialize a 2D vector with 'n' rows and 'm' columns
        vector<vector<int>> res(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // The element at (i, j) moves to (j, i)
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};