#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
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
#include <functional>
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

const int N = 110000;
ll dp[N][5];

// 貰うDPで実装
int main()
{
  int n;
  cin >> n;
  vector<int> T(n);
  vector<int> X(n);
  vector<ll> A(n);
  for (int i = 0; i < n; i++)
  {
    cin >> T[i] >> X[i] >> A[i];
  }

  int index = 0;
  int next_t = T[0];

  int t, x;
  ll a;
  bool flag = false;

  for (int i = 1; i < N; i++)
  {
    if (i == next_t)
    {
      x = X[index];
      a = A[index];
      index++;
      next_t = T[index];
      flag = true;
    }
    for (int j = 0; j < 5; j++)
    {
      chmax(dp[i][j], dp[i - 1][j]);
      if (j != 0 && j - 1 < i)
        chmax(dp[i][j], dp[i - 1][j - 1]);
      if (j != 4 && j + 1 < i)
        chmax(dp[i][j], dp[i - 1][j + 1]);
    }
    if (flag)
    {
      if (x <= i)
        chmax(dp[i][x], a + dp[i - 1][x]);
      if (x != 0 && x - 1 < i)
        chmax(dp[i][x], a + dp[i - 1][x - 1]);
      if (x != 4 && x + 1 < i)
        chmax(dp[i][x], a + dp[i - 1][x + 1]);
      flag = false;
    }
  }
  ll ans = 0;
  for (int i = 0; i < 5; i++)
  {
    ans = max(ans, dp[N - 1][i]);
  }
  cout << ans << endl;

  return 0;
}