class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < board.size(); i++){
            set<char> seen;
            for (int j = 0; j < board.size(); j++){
                if (board[i][j] != '.' && 
                (seen.find(board[i][j]) != seen.end())){
                    return false;
                }
            }
        }

        for (int i = 0; i < board.size(); i++){
            set<char> seen;
            for (int j = 0; j < board.size(); j++){
                if (board[j][i] != '.' && 
                (seen.find(board[j][i]) != seen.end())){
                    return false;
                }
            }
        }


        // Iterate through all 9 blocks (blockRow and blockCol represent the top-left of each 3x3 grid)
for (int blockRow = 0; blockRow < 9; blockRow += 3) {
    for (int blockCol = 0; blockCol < 9; blockCol += 3) {
        
        std::set<char> seen; // Reset the set for every new 3x3 block
        
        // Traverse the current 3x3 block
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char current = board[blockRow + i][blockCol + j];
                
                if (current != '.') {
                    // If the character is already in the set, it's a duplicate
                    if (seen.find(current) != seen.end()) {
                        return false; 
                    }
                    // Otherwise, add it to the set
                    seen.insert(current);
                }
            }
        }
        
    }
}





        return true;
        
    }




};


