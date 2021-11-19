// interview bit recursive tc maybe n*(4^n)
int evaluate(string s,int i,int j,bool isTrue){
  if(i==j){
    if(isTrue==false) return s[i]=='F';
    else if(isTrue==true) return s[i]=='T';
  }
  int answer=0;
  for(int k=i;k<j;k+=2){
    int lf=evaluate(s,i,k,false);
    int lt=evaluate(s,i,k,true);
    int rf=evaluate(s,k+2,j,false);
    int rt=evaluate(s,k+2,j,true);
    if(s[k+1]=='&'){
      if(isTrue==true) answer+=(rt*lt);
      else answer+=(rf*lf)+(rf*lt)+(rt*lf);
    }else if(s[k+1]=='|'){
      if(isTrue==true) answer+=(rt*lt)+(rf*lt)+(rt*lf);
      else answer+=(rf*lf);
    }else if(s[k+1]=='^'){
      if(isTrue==true) answer+=(rt*lf)+(rf*lt);
      else answer+=(rt*lt)+(rf*lf);
    }
  }
  return answer;
}
int Solution::cnttrue(string A) {
  return evaluate(A,0,A.length()-1,true);
}

// interviewbit top down tc n*n*n sp n*n*2
unordered_map<string,int> dp;
int evaluate(string s,int i,int j,int isTrue){
  if(i==j){
    if(isTrue==0) return s[i]=='F';
    else return s[i]=='T';
  }
  // You can also write this statement
  // string key=to_string(i)+to_string(j)+to_string(isTrue);
  string key=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
  if(dp.find(key)!=dp.end()) return dp[key];
  int answer=0;
  for(int k=i;k<j;k+=2){
    int lf=evaluate(s,i,k,0);
    int lt=evaluate(s,i,k,1);
    int rf=evaluate(s,k+2,j,0);
    int rt=evaluate(s,k+2,j,1);
    if(s[k+1]=='&'){
      if(isTrue==1) answer+=(rt*lt);
      else answer+=(rf*lf)+(rf*lt)+(rt*lf);
    }else if(s[k+1]=='|'){
      if(isTrue==1) answer+=(rt*lt)+(rf*lt)+(rt*lf);
      else answer+=(rf*lf);
    }else if(s[k+1]=='^'){
      if(isTrue==1) answer+=(rt*lf)+(rf*lt);
      else answer+=(rt*lt)+(rf*lf);
    }
  }
  return dp[key]=answer;
}
int Solution::cnttrue(string A) {
  // writing dp.clear() is important
  dp.clear();
  return evaluate(A,0,A.length()-1,1);
}
