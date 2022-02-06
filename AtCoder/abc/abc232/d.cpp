#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const int inf = 1e6;
// using Graph = vector<vector<string>>;

// 初めからの幅優先 
int main(){
  int h,w; 
  cin >> h >> w;
  vector<string>g(h);
  for (int i = 0; i < h; i++)
  {
    cin >> g[i];
  }
  vector<vector<int>>dp(h,vector<int>(w,0));
  queue<pair<int,int>> que;

  dp[0][0] = 1;
  que.push(make_pair(0,0));
  int max_dp = 0;
  while (!que.empty()) {
      pair<int,int> v = que.front();
      que.pop();
      int i = v.first;
      int j = v.second;
      if(g[i][j] == '#') continue;
      chmax(max_dp, dp[i][j]);

      if(i+1 < h && dp[i+1][j] <= dp[i][j]){
        chmax(dp[i+1][j], dp[i][j] + 1);
        que.push(make_pair(i+1,j));
      } 
      if(j+1 < w && dp[i][j+1] <= dp[i][j]) {
        chmax(dp[i][j+1], dp[i][j] + 1);
        que.push(make_pair(i,j+1));
      }

  }


  
  cout << max_dp << endl;
  return 0;
}

// 終わりからのdp
int main(){
  int h,w;
  cin >> h >> w;
  vector<string>s(h);
  for (int i = 0; i < h; i++)
  {
    cin >> s[i];
  }
  vector<vector<int>>dp(h,vector<int>(w,0));
  for (int i = h-1; i >= 0; i--)
  {
    for (int j = w-1; j >= 0; j--)
    {
      if(s[i][j] == '#') continue;
      dp[i][j] = 1;
      if(i+1 < h) chmax(dp[i][j], dp[i+1][j] + 1);
      if(j+1 < w) chmax(dp[i][j], dp[i][j+1] + 1);
    }
    
  }
  cout << dp[0][0] << endl;
  
  return 0;
}