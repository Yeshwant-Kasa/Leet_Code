class Solution {
public:
int m,n;
vector<vector<int>>dp;
int dfs(vector<vector<int>>& grid, int i, int j){
    if(j==n-1) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    int maxMoves =0;
    vector<int> directions = {-1,0,1};
    for(int d: directions){
        int ni=i+d, nj=j+1;
        if(ni >= 0 && ni <m && grid[ni][nj] > grid[i][j]){
            maxMoves = max(maxMoves, 1+dfs(grid, ni, nj));
        }  
    }
    return dp[i][j] = maxMoves;
}
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        dp.assign(m,vector<int>(n,-1));
        int maxSteps =0;
        for(int i=0;i<m;i++){
            maxSteps = max(maxSteps, dfs(grid,i,0));
        }
        return maxSteps;
    }
};