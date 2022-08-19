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
/*
https://algo-logic.info/segment-tree/#toc_id_1_1
配列の i 番目が表すノード dat[i] の子
左の子 : dat[2*i+1]
右の子 : dat[2*i+2]
配列の i 番目が表すノードdat[i]の親
親 : dat[(i-1)/2]
/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    set(int i, T x), i番目の要素をxにセット。O(1)
    build(): まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
    find_rightest(a,b,x): [a,b) で x以下の要素を持つ最右位置を求める。O(log(n))
    find_leftest(a,b,x): [a,b) で x以下の要素を持つ最左位置を求める。O(log(n))
*/
template <typename T>
struct RMQ
{
  const T e = numeric_limits<T>::max();
  function<T(T, T)> fx = [](T x1, T x2) -> T
  { return min(x1, x2); };
  int n;
  vector<T> dat;
  RMQ(int n_) : n(), dat(n_ * 4, e)
  {
    int x = 1;
    while (n_ > x)
    {
      x *= 2;
    }
    n = x;
  }

  void set(int i, T x) { dat[i + n - 1] = x; }
  void build()
  {
    for (int k = n - 2; k >= 0; k--)
      dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
  }

  void update(int i, T x)
  {
    i += n - 1;
    dat[i] = x;
    while (i > 0)
    {
      i = (i - 1) / 2; // parent
      dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }

  // the minimum element of [a,b)
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  T query_sub(int a, int b, int k, int l, int r)
  {
    if (r <= a || b <= l)
    {
      return e;
    }
    else if (a <= l && r <= b)
    {
      return dat[k];
    }
    else
    {
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }

  int find_rightest(int a, int b, T x) { return find_rightest_sub(a, b, x, 0, 0, n); }
  int find_leftest(int a, int b, T x) { return find_leftest_sub(a, b, x, 0, 0, n); }
  int find_rightest_sub(int a, int b, T x, int k, int l, int r)
  {
    if (dat[k] > x || r <= a || b <= l)
    { // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn a-1
      return a - 1;
    }
    else if (k >= n - 1)
    { // 自分が葉ならその位置をreturn
      return (k - (n - 1));
    }
    else
    {
      int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
      if (vr != a - 1)
      { // 右の部分木を見て a-1 以外ならreturn
        return vr;
      }
      else
      { // 左の部分木を見て値をreturn
        return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
      }
    }
  }
  int find_leftest_sub(int a, int b, T x, int k, int l, int r)
  {
    if (dat[k] > x || r <= a || b <= l)
    { // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn b
      return b;
    }
    else if (k >= n - 1)
    { // 自分が葉ならその位置をreturn
      return (k - (n - 1));
    }
    else
    {
      int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
      if (vl != b)
      { // 左の部分木を見て b 以外ならreturn
        return vl;
      }
      else
      { // 右の部分木を見て値をreturn
        return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
      }
    }
  }
};

// Range Minimum Query
int main(){
  int N = 8;
  RMQ <int> segtree(N);
  vector<int> a = {3,5,2,11,9,50,20,8};
  for(int i = 0; i < N; i++){
    segtree.set(i, a[i]);
  }
  segtree.build();
  int ans = segtree.query(0,8);
  cout << ans << endl;
  // 2
  return 0;
}