// leetcode recursive tc 2^(n-1)
// T(N) = T(N-1) + T(N-2) + ... + T(1)
// T(N-1) = T(N-2) + ... + T(1)
// T(N) - T(N-1) = T(N-1)
// T(N) = 2*T(N-1)
// similarly T(N-1) = 2T(N-2) and so on
// T(N) = 2 * 2 * .... 2 * T(1) {n-1} times => ~ 2^N-1 => O(2^N)
bool dictContains(string s,vector<string>& wordDict){
  for(int i=0;i<wordDict.size();i+=1){
    if(s==wordDict[i]) return true;
  }
  return false;
}
bool findString(string s, int n,vector<string>& wordDict) {
  if(n==0) return true;
  for(int i=1;i<=n;i+=1){
    // if dictContains will return true then only we will recur. This is the property of &&
    if(
      // worst case will be when dict contains every substring
      // i.e we will call the function for each and every substring
      dictContains(s.substr(0,i),wordDict)
      and
      findString(s.substr(i,n-i),n-i,wordDict)
    ) return true;
  }
  return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
  return findString(s,s.length(),wordDict);
}

// leetcode top down tc sp n*n
unordered_map<string,bool> mp;
bool dictContains(string s,vector<string>& wordDict){
    for(int i=0;i<wordDict.size();i+=1){
        if(s==wordDict[i]) return true;
    }
    return false;
}
bool findString(string s, int n,vector<string>& wordDict) {
    if(n==0) return true;
    string key=s+to_string(n);
    if(mp.count(key)) return mp[key];
    for(int i=1;i<=n;i+=1){
        if(
            dictContains(s.substr(0,i),wordDict)
            and
            findString(s.substr(i,n-i),n-i,wordDict)
        ) return mp[key]=true;
    }
    return mp[key]=false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    return findString(s,s.length(),wordDict);
}
