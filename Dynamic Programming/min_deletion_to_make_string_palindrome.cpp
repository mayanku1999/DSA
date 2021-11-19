// this question is exactly the same as
// min number of insertion to make a string palindrome
// EXACTLY same
// write bottom up and recursive on your own

// gfg tested top down
int dp[1001][1001];
int lcs(string& s,string& t,int m,int n){
  if(n==0||m==0) return 0;
  else if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
  else if(s[m-1]==t[n-1]) return dp[m-1][n-1]=1+lcs(s,t,m-1,n-1);
  else return dp[m-1][n-1]=max(lcs(s,t,m-1,n),lcs(s,t,m,n-1));
}
int minimumNumberOfDeletions(string s) {
  string t=s;
  reverse(t.begin(),t.end());
  memset(dp,-1,sizeof(dp));
  int m=s.length(),n=t.length();
  return m-lcs(s,t,m,n);
}
