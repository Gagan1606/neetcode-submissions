class Solution {
public:
int util(vector<vector<int>> &grid){
    int n=grid.size(), m=grid[0].size(), res=0, fresh=0;
    queue<vector<int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1) fresh++;
            if(grid[i][j]==2){
                q.push({i, j});
            }
        }
    }
    vector<int> dx={1, -1, 0, 0}, dy={0, 0, 1, -1};

    while(!q.empty() && fresh>0){
        int size=q.size();
        while(size--){
            int x=q.front()[0], y=q.front()[1];
            q.pop();
            for(int k=0; k<4; k++){
                int xi=x+dx[k], yi=y+dy[k];
                if(xi>=0 && xi<n && yi>=0 && yi<m){
                    if(grid[xi][yi]==1){
                        grid[xi][yi]=2;
                        q.push({xi, yi});
                        fresh--;
                    }
                }
            }
        }
        res++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    return res;
}
    int orangesRotting(vector<vector<int>>& grid) {
        return util(grid);
    }
};
