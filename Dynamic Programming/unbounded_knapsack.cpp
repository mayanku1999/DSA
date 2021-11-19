// gfg recursive 2^n
int knapSackUtil(int val[],int wt[],int n,int W){
  if(n==0||W==0) return 0;
  else if(wt[n-1]>W) return knapSackUtil(val,wt,n-1,W);
  else return max(knapSackUtil(val,wt,n-1,W),val[n-1]+knapSackUtil(val,wt,n,W-wt[n-1]));
}
int knapSack(int n, int W, int val[], int wt[]){
  return knapSackUtil(val,wt,n,W);
}

// gfg top down tc sp n*w
int dp[1001][1001];
int knapSackUtil(int val[],int wt[],int n,int W){
  if(n==0||W==0) return 0;
  if(dp[n-1][W]!=-1) return dp[n-1][W];
  else if(wt[n-1]>W) return dp[n-1][W]=knapSackUtil(val,wt,n-1,W);
  else return dp[n-1][W]=max(knapSackUtil(val,wt,n-1,W),val[n-1]+knapSackUtil(val,wt,n,W-wt[n-1]));
}
int knapSack(int n, int W, int val[], int wt[]){
  memset(dp,-1,sizeof(dp));
  return knapSackUtil(val,wt,n,W);
}

// gfg bottom up sp tc n*w
int knapSack(int n, int w, int val[], int wt[]){
  int i,j,dp[n+1][w+1];
  for(i=0;i<=n;i+=1){
    for(j=0;j<=w;j+=1){
      if(i==0 or j==0) dp[i][j]=0;
      else if(j<wt[i-1]) dp[i][j]=dp[i-1][j];
      else dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
    }
  }
  return dp[n][w];
}
