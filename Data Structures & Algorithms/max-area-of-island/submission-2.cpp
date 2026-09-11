class Solution {
public:
void dfs(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&vis, int &currArea){
    vis[x][y]=1;
    currArea++;
    // if(grid[x][y]) currArea++;
    vector<int> dx={0, 0, 1, -1};
    vector<int> dy={1, -1, 0, 0};
    for(int i=0; i<4; i++){
        int newX=x+dx[i];
        int newY=y+dy[i];
        if(newX >= 0 && newY >= 0 && newX<grid.size() && newY<grid[0].size() && !vis[newX][newY] && grid[newX][newY]){

            dfs(x+dx[i], y+dy[i], grid, vis, currArea);}
    }
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=INT_MIN, currArea=0;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(!vis[i][j] && grid[i][j]) {
                    maxArea=max(currArea, maxArea);
                    currArea=0;
                    dfs(i, j, grid, vis, currArea);}
            }
        }
        maxArea = max(maxArea, currArea);
        return maxArea;
    }
};
