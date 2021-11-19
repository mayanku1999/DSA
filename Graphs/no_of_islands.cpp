// 200 leetcode tc row*col aux sp row*col
void traverse(vector<vector<char>>& grid,int i,int j){
  if(i<0 or i==grid.size() or j<0 or j==grid[0].size() or grid[i][j]!='1') return;
  grid[i][j]='2';
  traverse(grid,i+1,j);
  traverse(grid,i,j+1);
  traverse(grid,i,j-1);
  traverse(grid,i-1,j);
}
int numIslands(vector<vector<char>>& grid) {
  int i,j,row=grid.size(),col=grid[0].size();
  int islands=0;
  for(i=0;i<row;i+=1){
    for(j=0;j<col;j+=1){
      if(grid[i][j]=='1'){
        traverse(grid,i,j);
        islands+=1;
      }
    }
  }
  return islands;
}
