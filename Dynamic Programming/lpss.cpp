// WRONG LOGIC: find lcss of original string and its reverse
// example string a=aacaxyzacaa
// in above string if you try to find lcss of string a with reverse of string a
// then answer will be acaa which is not palindrome thus it wont work here unlike lps
// in lps this logic will work but in lpss this logic wont work as shown above

// simple brute force solution tc n^3
bool check(string t){
  int i=0,j=t.length()-1;
  while(i<j){
    if(t[i]!=t[j]) return false;
    i+=1;j-=1;
  }
  return true;
}
string longestPalindrome(string s) {
  int i,j,n=s.length(),len=0;
  string result;
  for(i=0;i<n;i+=1){
    for(j=1;j<n-i+1;j+=1){
      string t=s.substr(i,j);
      if(check(t)==true and t.length()>len){
        len=t.length();
        result=t;
      }
    }
  }
  return result;
}

// dp(i, j) represents whether s(i ... j) can form a palindromic substring
// j must be greater than or equal to i at all times. Why?
// i is the starting index of the substring, j is the ending index of the substring.
// It makes no sense for i to be greater than j
// FURTHER READING: https://leetcode.com/problems/longest-palindromic-substring/discuss/2921/Share-my-Java-solution-using-dynamic-programming
string longestPalindrome(string s) {
  int i,j,k,n=s.length(),start=0,len=1;
  bool dp[n][n];
  memset(dp,false,sizeof(dp));
  // calculating answer for palindromic substrings of len 1
  for(i=0;i<n;i+=1){
    dp[i][i]=true;
  }
  // calculating answer for palindromic substrings of len 2
  for(i=0;i<n-1;i+=1){
    if(s[i]==s[i+1]){
      dp[i][i+1]=true;
      len=2;
      start=i;
    }
  }
  // calculating answer for palindromic substrings of len 3 or more
  for(k=3;k<=n;k+=1){
    for(i=0;i<n-k+1;i+=1){
      j=i+k-1;
      if(s[i]==s[j] and dp[i+1][j-1]){
        dp[i][j]=true;
        len=k;
        start=i;
      }
    }
  }
  return s.substr(start,len);
}

// another way of calculating 2d array
int n=s.length();
bool p[n][n];
for(i=0;i<n;i+=1) p[i][i]=true;
for(len=2;len<=n;len+=1){
  for(i=0;i<n-len+1;i+=1){
    j=i+len-1;
    if(len==2) p[i][j]=(s[i]==s[j]);
    else p[i][j]=(s[i]==s[j])&&p[i+1][j-1];
  }
}
