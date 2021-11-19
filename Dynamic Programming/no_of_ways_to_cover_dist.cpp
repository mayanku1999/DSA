// leetcode tc 2^n
int findWays(int n){
  if(n==1) return 1;
  if(n==2) return 2;
  return findWays(n-2)+findWays(n-1);
}
int climbStairs(int n) {
  return findWays(n);
}

// leetcode top down tc sp n
int dp[46];
int findWays(int n){
  if(n==1) return 1;
  if(n==2) return 2;
  if(dp[n]!=-1) return dp[n];
  return dp[n]=findWays(n-2)+findWays(n-1);
}
int climbStairs(int n) {
  memset(dp,-1,sizeof(dp));
  return findWays(n);
}

// leetcode bottom up tc sp n
int climbStairs(int n){
  if(n==1) return 1;
  int dp[n];
  dp[0]=1;
  dp[1]=2;
  for(int i=2;i<n;i+=1){
    dp[i]=dp[i-1]+dp[i-2];
  }
  return dp[n-1];
}
