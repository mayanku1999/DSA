// leetcode integer break top down tc sp n*n
int dp[58][59];
int f(int length[],int n,int allowed){
  if(allowed==0)return 1;
  else if(n==0) return 0;
  else if(dp[n-1][allowed]!=-1) return dp[n-1][allowed];
  else if(length[n-1]>allowed) return dp[n-1][allowed]=f(length,n-1,allowed);
  else return dp[n-1][allowed]=max(
    f(length,n-1,allowed),length[n-1]*f(length,n,allowed-length[n-1])
  );
}
int integerBreak(int n) {
  int length[n-1],i;
  memset(dp,-1,sizeof(dp));
  for(i=0;i<n-1;i+=1) length[i]=i+1;
  return f(length,n-1,n);
}

// leetcode integer break tc 2^n
int findMaxProduct(int length[],int n,int allowed_length){
  if(n==1) return 0;
  if(allowed_length==0) return 1;
  if(length[n-1]>allowed_length)
  return findMaxProduct(length,n-1,allowed_length);
  else return
  max(
    length[n-1]*findMaxProduct(length,n,allowed_length-length[n-1]),
    findMaxProduct(length,n-1,allowed_length)
  );
}
int integerBreak(int n){
  int length[n];
  for(int i=0;i<n;i+=1) length[i]=i;
  return findMaxProduct(length,n,n);
}

// top down tc sp n*n
int dp[58][59];
int findMaxProduct(int length[],int n,int allowed_length){
  // For n=1, we are taking 0th index and length[0]=0 so we will return
  if(n==1) return 0;
  if(allowed_length==0) return 1;
  if(dp[n-1][allowed_length]!=-1) return dp[n-1][allowed_length];
  if(length[n-1]>allowed_length)
  return dp[n-1][allowed_length]=findMaxProduct(length,n-1,allowed_length);
  else return
  dp[n-1][allowed_length]=max(
    length[n-1]*findMaxProduct(length,n,allowed_length-length[n-1]),
    findMaxProduct(length,n-1,allowed_length)
  );
}
int integerBreak(int n){
  int length[n];
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i+=1) length[i]=i;
  return findMaxProduct(length,n,n);
}

//top down withour length array tc sp n*n
int dp[58][59];
int findMaxProduct(int n,int allowed_length){
  if(n==1) return 0;
  if(allowed_length==0) return 1;
  if(dp[n-1][allowed_length]!=-1) return dp[n-1][allowed_length];
  if((n-1)>allowed_length)
  return dp[n-1][allowed_length]=findMaxProduct(n-1,allowed_length);
  else return
  dp[n-1][allowed_length]=max(
    (n-1)*findMaxProduct(n,allowed_length-(n-1)),
    findMaxProduct(n-1,allowed_length)
  );
}
int integerBreak(int n){
  memset(dp,-1,sizeof(dp));
  return findMaxProduct(n,n);
}
