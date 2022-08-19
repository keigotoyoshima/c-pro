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
  update(a,b,x): 区間[a,b) の要素を x に更新。O(log(n))
  query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct RMQ
{
  const T INF = numeric_limits<T>::max();
  int n;
  vector<T> dat, lazy;
  RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF)
  {
    int x = 1;
    while (n_ > x)
      x *= 2;
    n = x;
  }

  /* lazy eval */
  void eval(int k) // 配列のk番目を更新
  {
    if (lazy[k] == INF)
      return; // 更新するものが無ければ終了
    if (k < n - 1)
    { // 葉でなければ子に伝搬
      lazy[k * 2 + 1] = lazy[k];
      lazy[k * 2 + 2] = lazy[k];
    }
    // 自身を更新
    dat[k] = lazy[k];
    lazy[k] = INF;
  }
  
  // 区間更新
  void update(int a, int b, T x, int k, int l, int r)
  {
    // 遅延評価
    eval(k);
    if (a <= l && r <= b)
    { // 完全に内側の時
      lazy[k] = x;
      eval(k);
    }
    else if (a < r && l < b)
    {                                             // 一部区間が被る時
      update(a, b, x, k * 2 + 1, l, (l + r) / 2); // 左の子
      update(a, b, x, k * 2 + 2, (l + r) / 2, r); // 右の子
      dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

  void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }

  //  [a,b)の最小値を取得する
  // k:現在見ているノードの位置  [l,r):dat[k]が表している区間
  T query_sub(int a, int b, int k, int l, int r)
  {
    eval(k);
    if (r <= a || b <= l)
    { // 完全に外側の時
      return INF;
    }
    else if (a <= l && r <= b)
    { // 完全に内側の時
      return dat[k];
    }
    else
    { // 一部区間が被る時
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

  /* debug */
  inline T operator[](int a) { return query(a, a + 1); }
  void print()
  {
    for (int i = 0; i < 2 * n - 1; ++i)
    {
      cout << (*this)[i];
      if (i != n)
        cout << ",";
    }
    cout << endl;
  }
};

// Range Minimum Query
int main(){
  return 0;
}