class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // 1. Validate Rows
        for (int i = 0; i < board.size(); i++){
            set<char> seen;
            for (int j = 0; j < board.size(); j++){
                if (board[i][j] != '.') {
                    if (seen.find(board[i][j]) != seen.end()) {
                        return false;
                    }
                    seen.insert(board[i][j]); // <--- FIX: Missing insert
                }
            }
        }

        // 2. Validate Columns
        for (int i = 0; i < board.size(); i++){
            set<char> seen;
            for (int j = 0; j < board.size(); j++){
                if (board[j][i] != '.') {
                    if (seen.find(board[j][i]) != seen.end()) {
                        return false;
                    }
                    seen.insert(board[j][i]); // <--- FIX: Missing insert
                }
            }
        }

        // 3. Validate 3x3 Sub-grids
        for (int blockRow = 0; blockRow < 9; blockRow += 3) {
            for (int blockCol = 0; blockCol < 9; blockCol += 3) {
                set<char> seen; 
                
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char current = board[blockRow + i][blockCol + j];
                        
                        if (current != '.') {
                            if (seen.find(current) != seen.end()) {
                                return false; 
                            }
                            seen.insert(current); // (This one was correct!)
                        }
                    }
                }
            }
        }

        return true;
    }
};