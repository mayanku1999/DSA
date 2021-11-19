// leetcode top down tc sp m*n
int dp[200][200];
int solve(vector<vector<int>>& grid,int i,int j,int row,int col){
  if(i==row or j==col) return INT_MAX;
  else if(i==row-1 and j==col-1) return grid[i][j];
  else if(dp[i][j]!=-1) return dp[i][j];
  return dp[i][j]=grid[i][j]+min(
    {
      solve(grid,i+1,j,row,col),
      solve(grid,i,j+1,row,col),
    }
  );
}
int minPathSum(vector<vector<int>>& grid) {
  int row=grid.size(),col=grid[0].size();
  memset(dp,-1,sizeof(dp));
  return solve(grid,0,0,row,col);
}

// leetcode tc 2^(m*n)
int findMinimumSum(vector<vector<int>>& grid,int m,int n){
  if(m<0 or n<0) return INT_MAX;
  else if(m==0 && n==0) return grid[m][n];
  else return grid[m][n]+min(
    // move up
    findMinimumSum(grid,m-1,n),
    // move left
    findMinimumSum(grid,m,n-1)
  );
}
int minPathSum(vector<vector<int>>& grid) {
  return findMinimumSum(grid,grid.size()-1,grid[0].size()-1);
}

// top down tc sp m*n
int dp[200][200];
int findMinimumSum(vector<vector<int>>& grid,int m,int n){
  if(m<0 or n<0) return INT_MAX;
  else if(m==0 && n==0) return grid[m][n];
  else if(dp[m][n]!=-1) return dp[m][n];
  else return dp[m][n]=grid[m][n]+min(
    // move up
    findMinimumSum(grid,m-1,n),
    // move left
    findMinimumSum(grid,m,n-1)
  );
}
int minPathSum(vector<vector<int>>& grid) {
  memset(dp,-1,sizeof(dp));
  return findMinimumSum(grid,grid.size()-1,grid[0].size()-1);
}

// leetcode bottom up
int minPathSum(vector<vector<int>>& grid) {
  int i,j,m=grid.size(),n=grid[0].size();
  int dp[m][n];
  dp[0][0]=grid[0][0];
  for(i=1;i<n;i+=1) dp[0][i]=dp[0][i-1]+grid[0][i];
  for(i=1;i<m;i+=1) dp[i][0]=dp[i-1][0]+grid[i][0];
  cout<<"1:";
  for(i=1;i<m;i+=1){
    for(j=1;j<n;j+=1){
      dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
    }
  }
  cout<<"1:";
  return dp[m-1][n-1];
}
