from collections import deque
from typing import List

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return
            
        r = len(grid)
        c = len(grid[0])
        
        queue = deque()
        visited = [[False] * c for _ in range(r)]
        
        # 1. Add all starting treasures (0) to the queue
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 0:
                    queue.append((i, j, 0))
                    visited[i][j] = True

        # 2. Strict 4-Way Directions Vector (No diagonals allowed)
        directions = [
            (-1, 0), (1, 0),  # Up, Down
            (0, -1), (0, 1)   # Left, Right
        ]

        # 3. Process layer by layer
        while queue:
            ci, cj, current_dist = queue.popleft()

            for di, dj in directions:
                ni = ci + di
                nj = cj + dj

                if 0 <= ni < r and 0 <= nj < c:
                    # Only traverse unvisited empty lands (walls are -1)
                    if grid[ni][nj] != -1 and not visited[ni][nj]:
                        visited[ni][nj] = True
                        grid[ni][nj] = current_dist + 1
                        queue.append((ni, nj, current_dist + 1))
