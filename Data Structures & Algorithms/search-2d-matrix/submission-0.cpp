 class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rl = 0, rr = matrix.size() - 1;
        int num_cols = matrix[0].size();

        // 1. Binary search to find the potential row
        while (rl <= rr) {
            int rm = rl + ((rr - rl) / 2);
            
            // Check if target is within the bounds of this specific row
            if (matrix[rm][0] <= target && target <= matrix[rm][num_cols - 1]) {
                
                // 2. Binary search within the found row
                int l = 0, r = num_cols - 1;
                while (l <= r) {
                    int m = l + ((r - l) / 2);
                    if (matrix[rm][m] == target) {
                        return true;
                    } else if (matrix[rm][m] < target) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                return false; // Found the right row, but target wasn't in it
                
            } else if (matrix[rm][0] > target) {
                rr = rm - 1; // Target is in an earlier row
            } else {
                rl = rm + 1; // Target is in a later row
            }
        }
        return false;
    }
};