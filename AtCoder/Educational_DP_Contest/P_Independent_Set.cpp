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

struct UnionFind
{
  vector<int> par;

  // constructor
  UnionFind(int n) : par(n, -1) {}
  // initialize
  void init(int n) { par.assign(n, -1); }

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

vector<vector<int>> a;

ll dp[100010][2];
bool flag[100010];

void f(int node){
  // 後戻り防止
  // if(flag[node]) return;
  flag[node] = true;
  dp[node][0] = 1;
  dp[node][1] = 1;

  for(auto v: a[node]){
    if(!flag[v]){
      f(v);
      // 0が白,1が黒
      dp[node][0] *= (dp[v][1] + dp[v][0]) % MOD;
      dp[node][0] %= MOD;
      dp[node][1] *= dp[v][0];
      dp[node][1] %= MOD;
    }
  }
  // cout << "node " << node << endl;
  // cout << dp[node][0] << " : " << dp[node][1] << endl;
}

int main(){ 
  int n; cin >> n;
  a.resize(n);
  memset(flag, false, sizeof(flag));

  UnionFind uf(n);
  for(int i = 0; i < n-1; i++){
    int x,y; cin >> x >> y;
    x--; y--;
    a[x].push_back(y);
    a[y].push_back(x);
    uf.merge(x,y);
  }

  int root = uf.root(0);
  // cout << "root:"  << root << endl;
  f(root);

  int ans = (dp[root][0] + dp[root][1])%MOD;
  cout << ans << endl;
  return 0;
}