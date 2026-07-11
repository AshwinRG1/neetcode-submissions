#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;
        
        queue<pair<int,int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Only start a BFS if we find unvisited land ('1')
                if (grid[i][j] == '1') {
                    islandCount++; // Found a new island
                    
                    // Mark as visited immediately and push to queue
                    grid[i][j] = '0'; 
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto node = q.front();
                        q.pop();
                        int row = node.first;
                        int col = node.second;
                        
                        for (int d = 0; d < 4; d++) {
                            int nr = row + directions[d][0];
                            int nc = col + directions[d][1];
                            
                            // Check boundaries and if it's land
                            if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == '1') {
                                grid[nr][nc] = '0'; // Mark visited before pushing to prevent duplicates
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return islandCount;
    }
};
