// tle on leetcode, running on gfg
// top down tc n*n*n sp n*n
// dont forget to use '&'
int dp[2001][2001];
bool isPalindrome(string& s,int i,int j){
  while(i<j){
    if(s[i]!=s[j]) return false;
    i+=1;
    j-=1;
  }
  return true;
}
int minimumCuts(string& s,int i,int j){
  if(i==j or isPalindrome(s,i,j)) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  int answer=INT_MAX;
  for(int k=i;k<j;k+=1){
    int cuts=1+minimumCuts(s,i,k)+minimumCuts(s,k+1,j);
    answer=min(answer,cuts);
  }
  return dp[i][j]=answer;
}
int minCut(string s) {
  memset(dp,-1,sizeof(dp));
  return minimumCuts(s,0,s.length()-1);
}

// leetcode top down tc i guess n*n sp n
// observe the minor change in the for loop
// since 'j' is not changing here, there is no need to use 2d array
// and also no need to use j in minimumCuts function. Use it in isPalindrome tho.
// Write s.length()-1 instead of 'j' in minimumCuts
int dp[2001];
bool isPalindrome(string& s,int i,int j){
  while(i<j){
    if(s[i]!=s[j]) return false;
    i+=1;
    j-=1;
  }
  return true;
}
int minimumCuts(string& s,int i,int j){
  if(i==j or isPalindrome(s,i,j)) return 0;
  if(dp[i]!=-1) return dp[i];
  int answer=INT_MAX;
  for(int k=i;k<j;k+=1){
    if(isPalindrome(s,i,k)){
      int cuts=1+minimumCuts(s,k+1,j);
      answer=min(answer,cuts);
    }
  }
  return dp[i]=answer;
}
int minCut(string s) {
  memset(dp,-1,sizeof(dp));
  return minimumCuts(s,0,s.length()-1);
}

// for bottom up tc n*n, visit https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
// or visit submissions https://leetcode.com/problems/palindrome-partitioning-ii/
