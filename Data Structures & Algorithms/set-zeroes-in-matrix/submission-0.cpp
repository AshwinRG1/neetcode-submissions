class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Using your pair vector to store the coordinates of actual zeroes
        vector<pair<int,int>> adjust;
        
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                // FIX: Only store the coordinate if the cell is actually 0
                if (matrix[i][j] == 0) {
                    adjust.push_back({i,j});
                }
            }
        }
        
        // Loop through your saved coordinates
        for (int i = 0; i < adjust.size(); i++){
            // FIX: Passed 'matrix' as the second argument and added the missing semicolon
            setCol(adjust[i].second, matrix);
            setRow(adjust[i].first, matrix);
        }
    }

    void setCol(int j, vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        for (int k = 0; k < m; k++) {
            matrix[k][j] = 0;
        }
    }

    void setRow(int i, vector<vector<int>>& matrix) {
        int n = matrix[0].size(); 
        for (int k = 0; k < n; k++) {
            matrix[i][k] = 0;
        }
    }
};