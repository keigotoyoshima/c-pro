#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <assert.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};




int main(){
  string S; 
  string T; 
  cin >> S >> T; 
  int s_len = S.size();
  int t_len = T.size();
  vector<vector<int>>dp(s_len+1,vector<int>(t_len+1,0));
  // dp[i+1][j+1] = i,jまでの添字まで見た時の最大値
  for (int i = 0; i < s_len; i++)
  {
    char s = S[i];
    for (int j = 0; j < t_len; j++)
    {
      char t = T[j];
      if(s==t) chmax(dp[i+1][j+1], dp[i][j] + 1);
      chmax(dp[i+1][j+1], dp[i][j+1]);
      chmax(dp[i+1][j+1], dp[i+1][j]);
    }
  }
  
  string ans = "";
  int s_index = S.size();
  int t_index = T.size();

  while (s_index > 0 && t_index > 0)
  {
   if(dp[s_index][t_index] == dp[s_index-1][t_index]){
      --s_index;
    }else if(dp[s_index][t_index] == dp[s_index][t_index-1]){
      t_index--;
    }else{
      ans += S[s_index-1];
      s_index--;
      t_index--;
    }
  }
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  
  return 0;
}