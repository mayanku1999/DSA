// leetcode tc sp n*amount
// write recursive code of tc 2^n by simply removing 2d array. it will work
int dp[301][5001];
int coinChange(vector<int>& coins,int amount,int n){
  if(amount==0) return 1;
  if(n==0||amount<0) return 0;
  if(dp[n-1][amount]!=-1) return dp[n-1][amount];
  if(coins[n-1]>amount) return dp[n-1][amount]=coinChange(coins,amount,n-1);
  else return dp[n-1][amount]=coinChange(coins,amount,n-1)+coinChange(coins,amount-coins[n-1],n);
}
int change(int amount, vector<int>& coins) {
  memset(dp,-1,sizeof(dp));
  return coinChange(coins,amount,coins.size());
}

// leetcode bottom up tc sp n*amount
int change(int amount, vector<int>& coins) {
  int i,j,n=coins.size();
  int dp[n+1][amount+1];
  for(i=0;i<=n;i+=1) dp[i][0]=1;
  for(i=1;i<=amount;i+=1) dp[0][i]=0;
  for(i=1;i<=n;i+=1){
    for(j=1;j<=amount;j+=1){
      if(j<coins[i-1]) dp[i][j]=dp[i-1][j];
      else dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
    }
  }
  return dp[n][amount];
}
