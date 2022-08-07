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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int MOD = 998244353;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
// n=1,2,3...に対して
// dp[i][j][k] = i-1番目まででj個選んで、選んだ数の和をnで割ったあまりがkになる方法の数
const ll N = 110;
ll a[N], n;
ll dp[N][N][N];

void add(ll &x, ll y)
{
  x += y;
  x %= MOD;
}

ll solve(ll len){
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= n; i++)
  {
    dp[i][0][0] = 1;
    if(i == 0) continue;
    for (int left = 1; left <= len; left++)
    {
      for (int rem = 0; rem < len; rem++)
      {
        add(dp[i][left][rem], dp[i - 1][left][rem]);
        add(dp[i][left][rem], dp[i - 1][left - 1][(((rem - a[i]) % len) + len) % len]);
      }
    }
  }

  return dp[n][len][0];
}

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin  >> a[i];
  }
  ll sum = 0;
  for(int i = 1; i <= n; i++){
    add(sum,solve(i));
  }
  cout << sum << endl;
  return 0;
}