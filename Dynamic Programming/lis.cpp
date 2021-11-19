// leetcode recursive tc 2^n
int findLength(vector<int>& nums,int n,int prev){
  if(n==0) return 0;
  else if(prev==INT_MAX or nums[prev]>nums[n-1]){
    return max(1+findLength(nums,n-1,n-1),findLength(nums,n-1,prev));
  }else{
    return findLength(nums,n-1,prev);
  }
}
int lengthOfLIS(vector<int>& nums){
  return findLength(nums,nums.size(),INT_MAX);
}

// leetcode top down tc sp n*n
// we are using prev to store index of the previous value and not the actual value
// storing actual value will result in array index out of bounds because value can also be negative
int dp[2501][2501];
int findLength(vector<int>& nums,int n,int prev){
  if(n==0) return 0;
  else if(prev==INT_MAX){
    return max(1+findLength(nums,n-1,n-1),findLength(nums,n-1,prev));
  }else if(dp[n-1][prev]!=-1){
    return dp[n-1][prev];
  }else if(nums[prev]>nums[n-1]){
    return dp[n-1][prev]=max(1+findLength(nums,n-1,n-1),findLength(nums,n-1,prev));
  }else{
    return dp[n-1][prev]=findLength(nums,n-1,prev);
  }
}
int lengthOfLIS(vector<int>& nums){
  memset(dp,-1,sizeof(dp));
  return findLength(nums,nums.size(),INT_MAX);
}

// another leetcode top down tc sp n*n
int dp[2501][2501];
int findLength(vector<int>& nums,int n,int prev){
  if(n==0) return 0;
  else if(prev==INT_MAX){
    return max(1+findLength(nums,n-1,n-1),findLength(nums,n-1,prev));
  }else if(dp[n-1][prev]!=-1){
    return dp[n-1][prev];
  }else if(nums[prev]<=nums[n-1]){
    return dp[n-1][prev]=findLength(nums,n-1,prev);
  }else{
    return dp[n-1][prev]=max(1+findLength(nums,n-1,n-1),findLength(nums,n-1,prev));
  }
}
int lengthOfLIS(vector<int>& nums){
  memset(dp,-1,sizeof(dp));
  return findLength(nums,nums.size(),INT_MAX);
}
