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
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

// dp[i][j]=i番目の子供がもらった飴の数の合計がjの時の場合の数
ll dp[110][110000];
int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);

  
  // for(int i = 0; i < k; i++) cum[i+1] = cum[i] + a[i];

  dp[0][0] = 1;
  for (auto &v : a)
    cin >> v;
  for (int i = 1; i <= n; ++i)
  {       
    vector<ll> cum(k + 2, 0);
    for(int j = 0; j <= k; j++) cum[j+1] = (cum[j] + dp[i-1][j]);
    for (int j = 0; j <= k; j++)
    {
      dp[i][j] = cum[j+1] - cum[max((ll)0,j-a[i-1])];
      dp[i][j] %= MOD;
    }
  }

  // for(int i = 0; i < 10; i++){
  //   for(int j = 0;  j < 10; j++){
  //     cout << dp[i][j] << " " ;
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  cout << dp[n][k] << endl;
  return 0;
}