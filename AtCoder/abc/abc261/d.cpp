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
#include <iomanip>
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
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
// C -> index;
map<int, int> mp;
vector<ll> X;
vector<pair<ll, ll>> CY;
vector<ll>b;

int main(){
  int n, m;
  cin >> n >> m;
  X.resize(n+1);
  b.resize(n+1);
  for (int i = 0; i < n; i++)
  {
    cin >> X[i+1];
  }
  for (int i = 0; i < m; i++)
  {
    ll c, y; cin >> c >> y;
    b[c] = y;
  }


  // 初期化
  vector<vector<ll>>dp(n+1, vector<ll>(n+1, -1));
  // ll ans = rec(n,0);
  dp[0][0] = 0;


  for (int i = 1; i < n+1; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if(j == 0){
        for (int k = 0; k <= i-1; k++)
        {
          chmax(dp[i][j], dp[i-1][k]);
        }
      }else{
        // 表の場合
        dp[i][j] = dp[i-1][j-1] + b[j] + X[i];
      }
    }
  }

  // for (auto v : dp)
  // {
  //   for (auto nv : v)
  //   {
  //     cout << nv << ' '; 
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  ll ans = 0;
  for (int i = 0; i < n+1; i++)
  {
    chmax(ans, dp[n][i]);
  }
  cout << ans << endl;
  
  return 0;
}