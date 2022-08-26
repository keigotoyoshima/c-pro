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
#include <iomanip>
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
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};


int main(){
  int n; cin >> n;
  vector<double>p(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  // dp[i][j] = i-1番目までのコインを投げて表がj回の時の確率
  vector<vector<double>>dp(n+1,vector<double>(n+1,0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    }
  }

  int len = n/2 + 1;
  int index = n;
  double ans = 0;
  while (len)
  {
    ans += dp[n][index];
    index--;  
    len--;
  }

  // cout << endl;
  // for(auto v : dp){
  //   for(auto nv: v){
  //     cout << nv <<" " ;
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  cout << fixed << setprecision(10)  << ans << endl;
  return 0;
}