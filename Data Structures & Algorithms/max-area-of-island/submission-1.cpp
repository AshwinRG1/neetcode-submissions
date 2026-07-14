class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        queue<pair<int,int>> q;
        set<pair<int,int>> visited;

        for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            int temp = 0;
            if (grid[i][j] == 1){

                if (visited.find({i,j}) == visited.end()){

                    pair<int,int> source = {i,j};
                    visited.insert(source);
                    q.push(source);

                    while (!q.empty()) {
    auto node = q.front();
    q.pop();
    temp++;

    for (int k = 0; k < 4; k++) {
        int nr = node.first + dir[k].first;
        int nc = node.second + dir[k].second;

        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
            continue;

        if (grid[nr][nc] == 0)
            continue;

        if (visited.count({nr, nc}))
            continue;

        visited.insert({nr, nc});
        q.push({nr, nc});
    }
}

                }

            }

            res = max(res,temp);
            
        }
        return res;
    }
};
