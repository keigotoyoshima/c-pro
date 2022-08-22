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

struct P{
  int s, d;
  P(int s=0, int d=0): s(s),d(d){}
};

template <typename X, typename M>
struct SegTreeLazy
{
  using FX = function<X(X, X)>;
  using FA = function<X(X, M)>;
  using FM = function<M(M, M)>;
  int n;
  FX fx;
  FA fa;
  FM fm;
  const X ex;
  const M em;
  vector<X> dat;
  vector<M> lazy;
  SegTreeLazy(int n_, FX fx_, FA fa_, FM fm_, X ex_, M em_)
      : n(), fx(fx_), fa(fa_), fm(fm_), ex(ex_), em(em_), dat(n_ * 4, ex), lazy(n_ * 4, em)
  {
    int x = 1;
    while (n_ > x)
      x *= 2;
    n = x;
  }

  void set(int i, X x) { dat[i + n - 1] = x; }
  void build()
  {
    for (int k = n - 2; k >= 0; k--)
      dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
  }

  /* lazy eval */
  void eval(int k)
  {
    if (lazy[k].s == em.s)
      return; // 更新するものが無ければ終了
    if (k < n - 1)
    { // 葉でなければ子に伝搬
      lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
      lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
    }
    // 自身を更新
    dat[k] = fa(dat[k], lazy[k]);
    lazy[k] = em;
  }

  void update(int a, int b, M x, int k, int l, int r)
  {
    eval(k);
    if (a <= l && r <= b)
    { // 完全に内側の時
      lazy[k] = fm(lazy[k], x);
      eval(k);
    }
    else if (a < r && l < b)
    {                                             // 一部区間が被る時
      update(a, b, x, k * 2 + 1, l, (l + r) / 2); // 左の子
      update(a, b, x, k * 2 + 2, (l + r) / 2, r); // 右の子
      dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }

  X query_sub(int a, int b, int k, int l, int r)
  {
    eval(k);
    if (r <= a || b <= l)
    { // 完全に外側の時
      return ex;
    }
    else if (a <= l && r <= b)
    { // 完全に内側の時
      return dat[k];
    }
    else
    { // 一部区間が被る時
      X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
  X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  /* debug */
  inline X operator[](int a) { return query(a, a + 1); }
  void print()
  {
    for (int i = 0; i < n; ++i)
    {
      cout << (*this)[i];
      if (i != n - 1)
        cout << ",";
    }
    cout << endl;
  }
};

// 区間更新型のRMQを構築
auto fx = [](P x1, P x2) -> P { return P(x1.s + x2.s, min(x1.d, x1.s + x2.d));};
auto fa = [](P x, P m) -> P { return m; };
auto fm = [](P m1, P m2) -> P { return m2; };
P ex = P(0,0);
P em = P(numeric_limits<int>::max(), numeric_limits<int>::max()); 

int main()
{
  int n, q; cin >> n >> q;
  string s; cin >> s;
  SegTreeLazy<P, P> seg(n, fx, fa, fm, ex, em);
  for (int i = 0; i < s.size(); i++)
  {
    char tem = s[i];
    if(tem == '('){
      P value = P(1,1);
      seg.set(i,value);
    }else if(tem == ')'){
      P value = P(-1,-1);
      seg.set(i,value);
    }
  }
  seg.build();
  for (int i = 0; i < q; i++)
  {
    int type, a, b; cin >> type >> a >> b;
    a--;b--;
    P left = seg.query(a,a+1);
    P right = seg.query(b,b+1);
    if(type==1){
      // 入れ替え
      // seg.print();
      seg.update(a,a+1,right);
      seg.update(b,b+1,left);
      // seg.print();
    }else{
      // 出力
      int dif = a-b;
      // 要素数が奇数の時
      if(dif%2==0){
        cout << "No" << endl;
        continue;
      }
      // 要素数が偶数の時
      int mid = (a+b)/2;
      P value = seg.query(a,b+1); 
      // 左の最小値と左の合計＋右の最小値が0以上かどうか
      // 合計が０であるかどうか. 左の最小値と左の合計＋右の最小値が0以上かどうか
      if(value.s == 0 && value.d >= 0){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
  

  return 0;
}