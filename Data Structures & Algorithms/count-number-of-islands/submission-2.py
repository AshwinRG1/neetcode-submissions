class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        m,n = len(grid), len(grid[0])
        res = 0

        def bfs(i,j):
            queue = deque([(i,j)])
            grid[i][j] = "0"


            while queue:
                r,c = queue.popleft()
                

                for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                    nr,nc = dr + r, dc + c
                    if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == "1":
                        queue.append((nr,nc))
                        grid[nr][nc] = "0"
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    res += 1
                    bfs(i,j)
        return res