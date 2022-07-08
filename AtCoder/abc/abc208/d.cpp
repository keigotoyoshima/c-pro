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

ll sum = 0;
void warshall_floyd(int n, vector<vector<ll>> &dp)
{
  for (int k = 0; k < n; k++)
  { // 経由する頂点
    for (int i = 0; i < n; i++)
    { // 始点
      for (int j = 0; j < n; j++)
      { // 終点
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        if (dp[i][j] == INF)
          continue;
        sum += dp[i][j];
      }
    }
  }
}

// ワーシャルフロイド法を使う問題
// 計算量O(n^3)
// https://atcoder.jp/contests/abc208/tasks/abc208_d
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> dp(n, vector<ll>(n, INF));
  for (int i = 0; i < n; i++)
  {
    dp[i][i] = 0;
  }
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    dp[a][b] = c;
  }

  warshall_floyd(n, dp);

  cout << sum << endl;

  return 0;
}
