A quick idea may be dp[i][j] = max( dp[i + 1][j] + v[i], dp[i][j - 1] + v[j]),
but here dp[i + 1][j] and dp[i][j - 1] are not the values directly available for us,
it depends on the move that our opponent makes.

Then we assume our opponent is as good as we are and always make optimal moves.
The worst case is that we will get the minimal value out of all possible situations
after our opponent make its move.

// leetcode recursive tc 4^n
int findWinner(vector<int>& nums,int i,int j){
  // If the current player is in a situation i > j, i.e. no choice for current player.
  // the game ends already; P1 simply gets 0 score for this round.
  if(i>j) return 0;
  // If the current player is in a situation i == j, i.e. only one choice for player
  // P1 simply gets `nums[i]` score.
  else if (i==j){
    return nums[i];
  }
  else return max(
    nums[i]+min(findWinner(nums,i+2,j),findWinner(nums,i+1,j-1)),
    nums[j]+min(findWinner(nums,i+1,j-1),findWinner(nums,i,j-2))
  );
}
bool PredictTheWinner(vector<int>& nums) {
  int score1=findWinner(nums,0,nums.size()-1);
  int total=0;
  for (int i : nums) {
    total += i;
  }
  return score1 >= total-score1;
}

// leetcode top down tc sp n*n
int dp[20][20];
int findWinner(vector<int>& nums,int i,int j){
  if(i>j) return 0;
  else if (i==j){
    return nums[i];
  }else if(dp[i][j]!=-1) return dp[i][j];
  else return dp[i][j]= max(
    nums[i]+min(findWinner(nums,i+2,j),findWinner(nums,i+1,j-1)),
    nums[j]+min(findWinner(nums,i+1,j-1),findWinner(nums,i,j-2))
  );
}
bool PredictTheWinner(vector<int>& nums){
  memset(dp,-1,sizeof(dp));
  int score1=findWinner(nums,0,nums.size()-1);
  int total=0;
  for (int i : nums) {
    total += i;
  }
  return score1 >= total-score1;
}
