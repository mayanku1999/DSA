// recursive leetcode tc row*col*(4^(row*col)) sp row*col
int solve(vector<vector<int>>& matrix,int i,int j,int prev){
  if(i<0 or i==matrix.size() or j<0 or j==matrix[0].size()) return 0;
  if(prev>=matrix[i][j]) return 0;
  int up=solve(matrix,i-1,j,matrix[i][j]);
  int down=solve(matrix,i+1,j,matrix[i][j]);
  int left=solve(matrix,i,j-1,matrix[i][j]);
  int right=solve(matrix,i,j+1,matrix[i][j]);
  return 1+max(up,max(down,max(left,right)));
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
  int answer=INT_MIN,i,j,row=matrix.size(),col=matrix[0].size();
  for(i=0;i<row;i+=1){
    for(j=0;j<col;j+=1){
      answer=max(answer,solve(matrix,i,j,-1));
    }
  }
  return answer;
}

// leetcode top down tc sp row*col
int dp[200][200];
int solve(vector<vector<int>>& matrix,int i,int j,int prev){
  if(i<0 or i==matrix.size() or j<0 or j==matrix[0].size()) return 0;
  else if(prev>=matrix[i][j]) return 0;
  else if(dp[i][j]!=-1) return dp[i][j];
  int up=solve(matrix,i-1,j,matrix[i][j]);
  int down=solve(matrix,i+1,j,matrix[i][j]);
  int left=solve(matrix,i,j-1,matrix[i][j]);
  int right=solve(matrix,i,j+1,matrix[i][j]);
  return dp[i][j]=1+max(up,max(down,max(left,right)));
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
  memset(dp,-1,sizeof(dp));
  int answer=INT_MIN,i,j,row=matrix.size(),col=matrix[0].size();
  for(i=0;i<row;i+=1){
    for(j=0;j<col;j+=1){
      answer=max(answer,solve(matrix,i,j,-1));
    }
  }
  return answer;
}
