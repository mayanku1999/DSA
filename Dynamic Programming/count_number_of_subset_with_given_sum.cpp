// gfg "perfect sum" tc sp n*sum
int t[101][100001];
int subset_sum(vector<int>& arr,int n,int sum){
  if(sum==0) return 1;
  if(n==0 || sum<0) return 0;
  if(t[n-1][sum]!=-1) return t[n-1][sum];
  if(arr[n-1]>sum) return t[n-1][sum]=subset_sum(arr,n-1,sum);
  return t[n-1][sum]=(subset_sum(arr,n-1,sum)+subset_sum(arr,n-1,sum-arr[n-1]));
}
int Solution::solve(vector<int> &A, int B) {
  memset(t,-1,sizeof(t));
  return subset_sum(A,A.size(),B);
}

// tc sp sum*n
int Solution::solve(vector<int> &arr, int sum) {
  int i,j,n=arr.size();
  int dp[n+1][sum+1];
  for(i=0;i<=n;i+=1) dp[i][0]=1;
  for(i=1;i<=sum;i+=1) dp[0][i]=0;
  for(i=1;i<=n;i+=1){
    for(j=1;j<=sum;j+=1){
      if(j<arr[i-1]){
        dp[i][j]=dp[i-1][j];
      }else{
        dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
      }
    }
  }
  return dp[n][sum];
}
