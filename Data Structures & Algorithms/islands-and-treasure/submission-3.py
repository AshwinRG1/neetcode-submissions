from collections import deque
from typing import List

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return
            
        r = len(grid)
        c = len(grid[0])
        
        # 1. Multi-Source Setup: Find ALL treasures (0) first and add them to the queue
        queue = deque()
        visited = [[False] * c for _ in range(r)]
        
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 0:  # 0 is typically the treasure/source
                    queue.append((i, j, 0))
                    visited[i][j] = True

        # 2. 8-Way Directions Vector (4 orthogonal + 4 diagonal)
        directions = [
            (-1, 0),  (1, 0),  (0, -1), (0, 1),   # Up, Down, Left, Right
            (-1, -1), (-1, 1), (1, -1), (1, 1)    # Diagonals
        ]

        # 3. Single BFS traversal layer-by-layer
        while queue:
            ci, cj, current_dist = queue.popleft()

            for di, dj in directions:
                ni = ci + di
                nj = cj + dj

                # Validate boundaries
                if 0 <= ni < r and 0 <= nj < c:
                    # Avoid walls (-1) and already visited spaces
                    if grid[ni][nj] != -1 and not visited[ni][nj]:
                        visited[ni][nj] = True
                        
                        # Update the empty room with the shortest 8-way distance
                        grid[ni][nj] = current_dist + 1
                        
                        queue.append((ni, nj, current_dist + 1))
