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


// AtCoderのジャッジはC++の場合1秒間に10^8回

int main()
{
  vector<int> v = {1, 2, 3, 4, 5};
  int n = 5;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cnt++;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      ans++;
    }
  }
  cout << cnt << endl;
  // cnt = (1 + 2 + 3 + 4 + 5) = 15;
  cout << ans << endl;
  // ans = 5 * 5 = 25;
  return 0;
}