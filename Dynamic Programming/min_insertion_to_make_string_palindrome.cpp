// find lcs of string a and its reverse
// subtract lcs from length of the string, that will be the answer
// write recursive on your own

// leetcode top down tc sp n*n
int dp[501][501];
int lcs(string& s, string& t,int m,int n){
  if(m==0 or n==0) return 0;
  else if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
  else if(s[m-1]==t[n-1]) return dp[m-1][n-1]=1+lcs(s,t,m-1,n-1);
  else return dp[m-1][n-1]=max(lcs(s,t,m,n-1),lcs(s,t,m-1,n));
}
int minInsertions(string s) {
  string t=s;
  int m=s.length();
  memset(dp,-1,sizeof(dp));
  reverse(t.begin(),t.end());
  return m-lcs(s,t,m,m);        
}

// leetcode bottom up tc sp n*n
int minInsertions(string s) {
  string t=s;
  reverse(t.begin(),t.end());
  int i,j,m=s.length(),n=t.length(),dp[m+1][n+1];
  for(i=0;i<=m;i+=1){
    for(j=0;j<=n;j+=1){
      if(i==0||j==0) dp[i][j]=0;
      else if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  return m-dp[m][n];
}
