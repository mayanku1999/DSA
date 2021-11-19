//gfg recursive tc 2^n
int knapSack(int W, int wt[], int val[], int n) {
  if(n==0||W==0) return 0;
  if(wt[n-1]>W) return knapSack(W,wt,val,n-1);
  else return max(knapSack(W,wt,val,n-1),val[n-1]+knapSack(W-wt[n-1],wt,val,n-1));
}

// interviewbit top down tc sp n*W
// n*W because we can store at max all possible pairs of n and W.
// remember to pass vector by reference else you will get tle
int t[1001][1001];
int solveKnapSack(int W,vector<int> &wt,vector<int> &val,int n) {
  if(n==0||W==0) return 0;
  if(t[n-1][W]!=-1) return t[n-1][W];
  if(wt[n-1]>W) return t[n-1][W]=solveKnapSack(W,wt,val,n-1);
  else return t[n-1][W]=max(solveKnapSack(W,wt,val,n-1),val[n-1]+solveKnapSack(W-wt[n-1],wt,val,n-1));
}
int Solution::solve(vector<int> &val, vector<int> &weight, int C) {
  memset(t,-1,sizeof(t));
  return solveKnapSack(C,weight,val,val.size());
}

// interviewbit bottom up tc sp n*c
int Solution::solve(vector<int> &val, vector<int> &weight, int c) {
  int i,j,n=val.size();
  int dp[n+1][c+1];
  for(i=0;i<=n;i+=1){
    for(j=0;j<=c;j+=1){
      if(i==0||j==0) dp[i][j]=0;
      else if(j<weight[i-1]){
        dp[i][j]=dp[i-1][j];
      }else{
        dp[i][j]=max(val[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
      }
    }
  }
  return dp[n][c];
}
