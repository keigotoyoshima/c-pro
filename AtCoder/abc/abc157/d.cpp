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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct UnionFind
{
  // 根ではない頂点のparは親となる頂点の値が入ってる
  // 根にはサイズ数が入っている。区別できるようにサイズはマイナスの値で入っている
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}

  void init(int n) { par.assign(n, -1); }

  // 根を返す
  int root(int x)
  {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool isSame(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (par[x] > par[y])
      swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x)
  {
    return -par[root(x)];
  }
};

int main()
{
  int N, M, K;
  cin >> N >> M >> K;
  UnionFind uf(N);
  vector<vector<int>> v(N);
  vector<int>beg(N);
  for (int i = 0; i < M; ++i)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    uf.merge(a, b);
    beg[a]++;
    beg[b]++;
  }

  
  for (int i = 0; i < K; ++i)
  {
    int c, d;
    cin >> c >> d;
    --c, --d;
    v[c].push_back(d);
    v[d].push_back(c);
  }


  
  for (int i = 0; i < N; i++)
  {
    int ans = uf.size(i) - 1 - beg[i];
    for(auto p : v[i]){
      if(uf.isSame(p,i)) --ans;
    }
    cout << ans << " ";
  }

  cout << endl;
  return 0;
}