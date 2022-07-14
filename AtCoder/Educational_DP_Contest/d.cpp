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
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
  int N;
  cin >> N;
  int W;
  cin >> W;
  vector<int> w(N);
  vector<ll> v(N);

  for (int i = 0; i < N; i++)
  {
    cin >> w[i] >> v[i];
  }

  vector<vector<ll>> dp(N, vector<ll>(W + 1, 0));
  for (int i = 0; i <= W; i++)
  {
    if (i - w[0] < 0)
      continue;
    dp[0][i] = v[0];
  }

  // dp[i][j]=i番目までにj以下の重さで選んだ時の価値の総和
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      // 次に選ぶ価値と重さ
      int weight = w[i + 1];
      ll value = v[i + 1];
      chmax(dp[i + 1][j], dp[i][j]);
      if (j - weight >= 0)
      {
        chmax(dp[i + 1][j], dp[i][j - weight] + value);
      }
    }
  }

  // for (auto nv : dp)
  // {
  //   for (auto v : nv)
  //   {
  //     cout << v << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  cout << dp[N - 1][W] << endl;

  return 0;
}