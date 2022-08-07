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
const int MOD = 998244353;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
// n=1,2,3...に対して
// dp[i][j][k] = i-1番目まででj個選んで、選んだ数の和をnで割ったあまりがkになる方法の数
ll n;
vector<ll> a;
ll dp[110][110][110];

void addmod(ll &x, ll y){
  x += y;
  x %= MOD;
}

ll solve(ll cnt)
{
  //先頭から2バイト進めた位置に「１」を3バイト書き込む
  // char buf[] = "ABCDEFGHIJK";
  // memset(buf + 2, '1', 3);
  // AB111FGHIJK

  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {

      for (int k = 0; k < cnt; k++)
      {
        ll tem =  (((k-a[i-1])%cnt)+cnt)%cnt;
        if (j > 0)
        {
          addmod(dp[i][j][k], dp[i - 1][j - 1][tem]);
        }
        addmod(dp[i][j][k], dp[i - 1][j][k]);
      }
    }
  }

  return dp[n][cnt][0];
}

int main()
{
  cin >> n;
  a.resize(n);
  for (auto &v : a)
    cin >> v;
  ll sum = 0;
  for (int i = 1; i <= n; i++)
  {
    addmod(sum,solve(i));
  }
  cout << sum << endl;

  return 0;
}