// leetcode top down tc sp n*n where n is length of string
// write dp[i][j] or write dp[i+1][j-1] in line 7,8,9
// tc of recursive solution is 2^n
int dp[1001][1001];
int lps(string& s,int i,int j){
  if(i==j) return 1;
  else if(i>j) return 0;
  else if(dp[i][j]!=-1) return dp[i][j];
  else if(s[i]==s[j]) return dp[i][j]=2+lps(s,i+1,j-1);
  else return dp[i][j]=max(lps(s,i,j-1),lps(s,i+1,j));
}
int longestPalindromeSubseq(string s) {
  memset(dp,-1,sizeof(dp));
  return lps(s,0,s.length()-1);
}

// leetcode another better top down approach
// lps of string s is simply lcs of (string s and rev(string s))
int dp[1001][1001];
int lps(string& s,string& t,int m,int n){
  if(m==0||n==0) return 0;
  if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
  else if(s[m-1]==t[n-1]) return dp[m-1][n-1]=1+lps(s,t,m-1,n-1);
  else return dp[m-1][n-1]=max(lps(s,t,m-1,n),lps(s,t,m,n-1));
}
int longestPalindromeSubseq(string s){
  string t=s;
  reverse(t.begin(),t.end());
  memset(dp,-1,sizeof(dp));
  return lps(s,t,s.length(),t.length());
}

// leetcode bottom up tc sp n*n
int longestPalindromeSubseq(string s){
  string t=s;
  reverse(t.begin(),t.end());
  int i,j,m=s.length(),n=t.length(),dp[m+1][n+1];
  for(i=0;i<=m;i+=1){
    for(j=0;j<=n;j+=1){
      if(i==0 or j==0) dp[i][j]=0;
      else if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  return dp[m][n];
}
