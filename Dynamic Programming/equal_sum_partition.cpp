// leetcode top down tc sp n*(sum/2)
// remember to pass vector by reference else you will get tle
int dp[201][10001];
bool canPartitionUtil(vector<int>& nums,int n,int sum){
  if(sum==0) return true;
  if(n==0||sum<0) return false;
  if(dp[n-1][sum]!=-1) return dp[n-1][sum];
  else if(sum<nums[n-1]) return dp[n-1][sum]=canPartitionUtil(nums,n-1,sum);
  else return dp[n-1][sum]=canPartitionUtil(nums,n-1,sum)||canPartitionUtil(nums,n-1,sum-nums[n-1]);
}
bool canPartition(vector<int>& nums) {
  memset(dp,-1,sizeof(dp));
  int sum=0;
  for(auto it:nums) sum+=it;
  if(sum%2==1) return false;
  else return canPartitionUtil(nums,nums.size(),sum/2);
}

// leetcode bottom up tc sp n*(sum/2)
bool canPartitionUtil(vector<int>& nums,int n,int sum){
  bool dp[n+1][sum+1];
  int i,j;
  for(i=0;i<=sum;i+=1) dp[0][i]=false;
  for(i=0;i<=n;i+=1) dp[i][0]=true;
  for(i=1;i<=n;i+=1){
    for(j=1;j<=sum;j+=1){
      if(j<nums[i-1]) dp[i][j]=dp[i-1][j];
      else dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
    }
  }
  return dp[n][sum];
}
bool canPartition(vector<int>& nums) {
  int sum=0;
  for(auto it: nums) sum+=it;
  if(sum%2==1) return false;
  else return canPartitionUtil(nums,nums.size(),sum/2);
}
