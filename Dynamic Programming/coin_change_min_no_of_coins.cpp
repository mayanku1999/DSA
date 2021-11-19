// leetcode tc sp n*amount. Write recursive algo by removing 2D array
int dp[13][10001];
int findMinCoins(vector<int>& coins, int n,int amount){
  if(amount==0) return 0;
  // n==0 means you have to make some amount with 0 coins. What is the minimum number of coins? Infinity-1 (added minus 1 to avoid overflow)
  else if(n==0) return INT_MAX-1;
  else if(dp[n-1][amount]!=-1) return dp[n-1][amount];
  else if(coins[n-1]>amount) return dp[n-1][amount]=findMinCoins(coins,n-1,amount);
  else return dp[n-1][amount]=min(findMinCoins(coins,n-1,amount),1+findMinCoins(coins,n,amount-coins[n-1]));
}
int coinChange(vector<int>& coins, int amount) {
  memset(dp,-1,sizeof(dp));
  int answer=findMinCoins(coins,coins.size(),amount);
  // coins=[2] amount=3 then INT_MAX-1 will be returned
  if(answer==INT_MAX-1) answer=-1;
  return answer;
}

// leetcode bottom up tc sp n*amount
int coinChange(vector<int>& coins, int amount) {
  int i,j,n=coins.size(),dp[n+1][amount+1];
  for(i=0;i<=n;i+=1) dp[i][0]=0;
  for(i=0;i<=amount;i+=1) dp[0][i]=INT_MAX-1;
  for(i=1;i<=n;i+=1){
    for(j=1;j<=amount;j+=1){
      if(j<coins[i-1]) dp[i][j]=dp[i-1][j];
      else dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
    }
  }
  if(dp[n][amount]==INT_MAX-1) dp[n][amount]=-1;
  return dp[n][amount];
}
