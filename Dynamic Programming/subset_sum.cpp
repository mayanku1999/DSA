// recursive tc 2^n and sp is o(1) probably
int subset_sum(vector<int>& arr,int n,int sum){
  if(sum==0) return 1;
  if(n==0 || sum<0) return 0;
  if(arr[n-1]>sum) return subset_sum(arr,n-1,sum);
  return subset_sum(arr,n-1,sum)||subset_sum(arr,n-1,sum-arr[n-1]);
}

// interview bit top down tc sp n*sum
// remember to pass vector by reference else you will get tle
// n<=100 and sum<=10^5
int t[101][100001];
int subset_sum(vector<int>& arr,int n,int sum){
  if(sum==0) return 1;
  if(n==0 || sum<0) return 0;
  if(t[n-1][sum]!=-1) return t[n-1][sum];
  if(arr[n-1]>sum) return t[n-1][sum]=subset_sum(arr,n-1,sum);
  return t[n-1][sum]=(subset_sum(arr,n-1,sum)||subset_sum(arr,n-1,sum-arr[n-1]));
}
int Solution::solve(vector<int> &A, int B) {
  memset(t,-1,sizeof(t));
  return subset_sum(A,A.size(),B);
}

// interview bit bottom up tc sp n*sum
int Solution::solve(vector<int> &arr, int sum) {
  int i,j,n=arr.size();
  bool dp[n+1][sum+1];
  for(i=0;i<=n;i+=1) dp[i][0]=true;
  for(i=1;i<=sum;i+=1) dp[0][i]=false;
  for(i=1;i<=n;i+=1){
    for(j=1;j<=sum;j+=1){
      if(j<arr[i-1]){
        dp[i][j]=dp[i-1][j];
      }else{
        dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
      }
    }
  }
  return dp[n][sum];
}

// interview bit bottom up tc n*sum sp 2*sum
int Solution::solve(vector<int> &arr, int sum) {
  int n=arr.size(),i,j;
  bool dp[2][sum+1];
  for(i=0;i<=n;i+=1){
    for(j=0;j<=sum;j+=1){
      if(j==0){
        dp[i%2][j]=true;
      }else if(i==0){
        dp[i][j]=false;
      }else if(j<arr[i-1]){
        dp[i%2][j]=dp[(i+1)%2][j];
      }else{
        dp[i%2][j]=dp[(i+1)%2][j] or dp[(i+1)%2][j-arr[i-1]];
      }
    }
  }
  return dp[n%2][sum];
}
