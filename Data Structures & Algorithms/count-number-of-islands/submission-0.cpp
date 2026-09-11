class Solution {
   public:
    void dfs(vector<vector<char>> &grid, vector<int> node, vector<vector<int>>& vis) {
        vis[node[0]][node[1]] = 1;
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int x = node[0] + dx[i];
            int y = node[1] + dy[i];

            if (x<grid.size() && y<grid[0].size() && grid[x][y]=='1' && !vis[x][y]) {
                dfs(grid, {x, y}, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1')  {
                        res++;
                        dfs(grid, {i, j}, vis);
                    }
            }
        }
        return res;

    }
};
