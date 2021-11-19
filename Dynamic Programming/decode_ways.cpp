// EXPLANATION: https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/

// 91 leetcode tle tc 2^n
int decodeString(string s,int n){
  if(n==0 or n==1) return 1;
  int count=0;
  if(s[n-1]!='0') count=decodeString(s,n-1);
  if(s[n-2]=='1' or (s[n-2]=='2' and s[n-1]<'7'))
  count+=decodeString(s,n-2);
  return count;
}
int numDecodings(string s) {
  if(s[0]=='0') return 0;
  return decodeString(s,s.length());
}

// 91 leetcode tc sp n
int dp[101];
int decodeString(string s,int n){
  if(dp[n]!=-1) return dp[n];
  if(n==0 or n==1) return 1;
  int count=0;
  if(s[n-1]!='0') count=decodeString(s,n-1);
  if(s[n-2]=='1' or (s[n-2]=='2' and s[n-1]<'7'))
  count+=decodeString(s,n-2);
  return dp[n]=count;
}
int numDecodings(string s) {
  memset(dp,-1,sizeof(dp));
  if(s[0]=='0') return 0;
  return decodeString(s,s.length());
}
