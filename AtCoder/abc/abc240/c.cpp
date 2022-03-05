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
const long long INFL = 1LL << 60;
const ll inf = 1e6;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }
  // dp[i+1][j] := i番目のジャンプで座標xにいるかどうか

  vector<vector<bool>> dp(n+1, vector<bool>(x + 1000, false));
  dp[0][0] = true;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < x; j++)
    {
      if (dp[i][j])
      {
        dp[i + 1][j + a[i]] = true;
        dp[i + 1][j + b[i]] = true;
      }
    }
  }

  if (dp[n][x])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}