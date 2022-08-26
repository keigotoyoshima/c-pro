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
  int n,k;
  cin >> n  >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  vector<int> dp(n, inf_int);
  dp[0] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= k; j++)
    {
      if(i+j < n)chmin(dp[i+j], dp[i]+ abs(h[i+j] - h[i]));
    }

  }
  // for(auto v: dp){
  //   cout << v << " ";
  // }
  // cout << endl;
  cout << dp[n - 1] << endl;

  return 0;
}