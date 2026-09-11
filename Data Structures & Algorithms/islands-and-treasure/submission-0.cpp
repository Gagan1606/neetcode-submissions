class Solution {
   public:
   int INF=2147483647;
    void util(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();
            for (int k = 0; k < 4; k++) {
                int xi = x + dx[k];
                int yi = y + dy[k];

                if (xi >= 0 && xi < n && yi >= 0 && yi < m) {
                    if (grid[xi][yi] != INF) continue;
                    grid[xi][yi] = grid[x][y] + 1;
                    q.push({xi, yi});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) { util(grid); }
};
