// visit https://www.geeksforgeeks.org/check-if-a-string-is-a-scrambled-form-of-another-string/
// to cover some corner cases

// There are O(n) possible split points. At each point, there are two possibilities: with swap and without swap.
// At each point, we recursively check the two substrings until both of them are single character,
// which takes time O(2^k+2^(n-k)), where k and n-k are the lengths of the two substrings.
// So, the recursive algorithm runs in exponential time, O(2^n)

// leetcode top down sp n*n tc n*n*n (It may also be n^4 because of substr)
unordered_map<string,bool> mp;
bool scrambleString(string s1,string s2){
  // If both strings are equal
  if(s1.compare(s2)==0) return true;
  // If both string are not equal and length of string is 1
  // that means there are two unmatching characters
  if(s2.length()==1) return false;
  string key=s1+" "+s2;
  // You can also write if(mp.count(key)==1) return mp[key];
  if(mp.find(key)!=mp.end()) return mp[key];
  int n=s2.length();
  for(int i=1;i<n;i+=1){
    if(
      // when we swapped two substrings
      (
        scrambleString(s1.substr(0,i),s2.substr(n-i,i))==true
        and
        scrambleString(s1.substr(i,n-i),s2.substr(0,n-i))==true
      )
      or
      // when we didn't swap two substrings
      (
        scrambleString(s1.substr(0,i),s2.substr(0,i))==true
        and
        scrambleString(s1.substr(i,n-i),s2.substr(i,n-i))==true
      )
    ){
      return mp[key]=true;
    }
  }
  return mp[key]=false;
}
bool isScramble(string s1, string s2) {
  // checking whether s1 and s2 are anagrams or not
  vector<int> count(26,0);
  for(int i=0;i<s1.length();i+=1){
      count[s1[i]-'a']++;
      count[s2[i]-'a']--;
  }
  // if s1 and s2 are not anagram return false else start processing
  for(auto it:count){
      if(it!=0) return false;
  }
  return scrambleString(s1,s2);
}
