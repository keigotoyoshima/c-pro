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
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};


/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct RMQ
{
  const T INF = numeric_limits<T>::max();
  int n;         // 葉の数
  vector<T> dat; // 完全二分木の配列
  RMQ(int n_) : n(), dat(n_ * 4, INF)
  { // 葉の数は 2^x の形
    int x = 1;
    while (n_ > x)
    {
      x *= 2;
    }
    n = x;
  }

  void update(int i, T x)
  {
    i += n - 1;
    dat[i] = x;
    while (i > 0)
    {
      i = (i - 1) / 2; // parent
      dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }

  // the minimum element of [a,b)
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  T query_sub(int a, int b, int k, int l, int r)
  {
    if (r <= a || b <= l)
    {
      return INF;
    }
    else if (a <= l && r <= b)
    {
      return dat[k];
    }
    else
    {
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
};

// Range Minimum Query
int main(){
  return 0;
}