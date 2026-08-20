class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j){
            if (grid[i][j] == 0){
                continue;
            }
            grid[i][j] = dfs(grid,i,j,r,c);
        }
    }

    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n){

        vector<pair<int,int>> dx = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;

        set<pair<int,int>> visited;
        queue<pair<int,int>> q;


        q.push({r,c});
        visited.insert({r,c});

        auto source = q.front();

        while (!q.empty()){
            auto front
            for (int i = 0; i < 4; i++){
                int nr = dx[i].first + r;
                int nc = dx[i].second + c;

                if (nr > r || nr < 0 || nc > c || nc < 0 || visited.find({nr,nc}) != visited.end()){
                    continue;
                }
                
                q.push({nr,nc});
                visited.insert({nr,nc});

                if (grid[nr][nc] == 0){
                    return res;
                }

            }
            res++;
        }

        return res;
    }
};
