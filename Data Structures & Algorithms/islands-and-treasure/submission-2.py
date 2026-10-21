from collections import deque
from typing import List

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return
            
        r = len(grid)
        c = len(grid[0])

        for i in range(r):
            for j in range(c):
                if grid[i][j] == -1: 
                    self.bfs(i, j, r, c, grid)

    def bfs(self, start_i: int, start_j: int, r: int, c: int, grid: List[List[int]]) -> None:
        queue = deque([(start_i, start_j, 0)])
        
        visited = [[False] * c for _ in range(r)]
        visited[start_i][start_j] = True
        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while queue:
            ci, cj, current_dist = queue.popleft()

            for di, dj in directions:
                ni = ci + di
                nj = cj + dj

                if (0 <= ni < r and 0 <= nj < c and 
                    grid[ni][nj] != -1 and 
                    not visited[ni][nj]):
                    
                    visited[ni][nj] = True
                    
                    grid[ni][nj] = min(current_dist + 1, grid[ni][nj])
          
                    queue.append((ni, nj, current_dist + 1))
