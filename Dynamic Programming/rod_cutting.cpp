// gfg recursive tc 2^n. This ques is just like unbounded knapSack
int cutRodUtil(int price[],int lengths[],int n,int allowed_length){
  if(n==0 || allowed_length==0) return 0;
  else if(lengths[n-1]>allowed_length)
  return cutRodUtil(price,lengths,n-1,allowed_length);
  else return
  max(
    cutRodUtil(price,lengths,n-1,allowed_length),
    price[n-1]+cutRodUtil(price,lengths,n,allowed_length-lengths[n-1])
  );
}
int cutRod(int price[], int n) {
  int lengths[n],allowed_length=n;
  for(int i=0;i<n;i+=1) lengths[i]=i+1;
  return cutRodUtil(price,lengths,n,allowed_length);
}

// same recursive approach but without length array
int cutRodUtil(int price[],int n,int allowed_length){
  if(n==0 || allowed_length==0) return 0;
  else if(n>allowed_length)
  return cutRodUtil(price,n-1,allowed_length);
  else return
  max(
    cutRodUtil(price,n-1,allowed_length),
    price[n-1]+cutRodUtil(price,n,allowed_length-(n))
  );
}
int cutRod(int price[], int n){
  int lengths[n],allowed_length=n;
  return cutRodUtil(price,n,allowed_length);
}

// gfg bottom up tc spc n*n
int cutRod(int price[], int n) {
  int i,j,lengths[n],allowed_length=n;
  for(i=0;i<n;i+=1) lengths[i]=i+1;
  int dp[n+1][allowed_length+1];
  for(i=0;i<=n;i+=1){
    for(j=0;j<=allowed_length;j+=1){
      if(i==0||j==0) dp[i][j]=0;
      else if(j<lengths[i-1]) dp[i][j]=dp[i-1][j];
      else dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-lengths[i-1]]);
    }
  }
  return dp[n][allowed_length];
}

// gfg top down tc sp n*n
int dp[1001][1001];
int cutRodUtil(int price[],int lengths[],int n,int allowed_length){
  if(n==0 || allowed_length<=0) return 0;
  else if(dp[n-1][allowed_length]!=-1) return dp[n-1][allowed_length];
  else if(lengths[n-1]>allowed_length)
  return dp[n-1][allowed_length]=cutRodUtil(price,lengths,n-1,allowed_length);
  else return
  dp[n-1][allowed_length]=
  max(
    cutRodUtil(price,lengths,n-1,allowed_length),
    price[n-1]+cutRodUtil(price,lengths,n,allowed_length-lengths[n-1])
  );
}
int cutRod(int price[], int n) {
  int lengths[n],allowed_length=n;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i+=1) lengths[i]=i+1;
  return cutRodUtil(price,lengths,n,allowed_length);
}
