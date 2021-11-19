// gfg recursive tc 2^n
int minDifferenceSubsets(int arr[],int n,int s1,int s2){
  //writing abs is important
  if(n==0) return abs(s1-s2);
  int include=minDifferenceSubsets(arr,n-1,s1+arr[n-1],s2);
  int exclude=minDifferenceSubsets(arr,n-1,s1,s2+arr[n-1]);
  return min(include,exclude);
}
int minDifference(int arr[], int n) {
  int s1=0,s2=0;
  return minDifferenceSubsets(arr,n,s1,s2);
}

// gfg top down tc sp n*sum
int dp[100][10001];
int minDifferenceSubsets(int arr[],int n,int s1,int s2){
  //writing abs is important
  if(n==0) return abs(s1-s2);
  if(dp[n][s1]!=-1) return dp[n][s1];
  return dp[n][s1]=min(
    minDifferenceSubsets(arr,n-1,s1+arr[n-1],s2),
    minDifferenceSubsets(arr,n-1,s1,s2+arr[n-1])
  );
}
int minDifference(int arr[], int n) {
  int s1=0,s2=0;
  memset(dp,-1,sizeof(dp));
  return minDifferenceSubsets(arr,n,s1,s2);
}

// another approach gfg recursive tc 2^n another approach
int minDifferenceSubsets(int arr[],int n,int s1,int total){
  if(n==0) return abs(s1-(total-s1));
  int include=minDifferenceSubsets(arr,n-1,s1+arr[n-1],total);
  int exclude=minDifferenceSubsets(arr,n-1,s1,total);
  return min(include,exclude);
}
int minDifference(int arr[], int n) {
  int s1=0,total=0;
  for(int i=0;i<n;i+=1) total+=arr[i];
  return minDifferenceSubsets(arr,n,s1,total);
}

// interviewbit top down tc sp n*sum
int dp[101][10001];
int minDifferenceSubsets(vector<int>& arr,int n,int s1,int total){
  if(n==0) return abs(s1-(total-s1));
  if(dp[n-1][s1]!=-1) return dp[n-1][s1];
  int include=minDifferenceSubsets(arr,n-1,s1+arr[n-1],total);
  int exclude=minDifferenceSubsets(arr,n-1,s1,total);
  return dp[n-1][s1]=min(include,exclude);
}
int Solution::solve(vector<int> &arr) {
  int s1=0,total=0,n=arr.size();
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i+=1) total+=arr[i];
  return minDifferenceSubsets(arr,n,s1,total);
}


// interviewbit bottom up tc sp n*sum
int minDifference(int arr[], int n) {
  int i,j,sum=0,answer;
  for(i=0;i<n;i+=1) sum+=arr[i];
  bool dp[n+1][sum+1];
  for(i=0;i<=n;i+=1) dp[i][0]=true;
  for(i=1;i<=sum;i+=1) dp[0][i]=false;
  for(i=1;i<=n;i+=1){
    for(j=1;j<=sum;j+=1){
      if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
      else dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
    }
  }
  for(i=sum/2;i<=sum;i+=1){
    if(dp[n][i]==true){
      answer=abs(i-(sum-i));
      break;
    }
  }
  return answer;
}
