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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<vector<int>> G;

// 視点までの距離の最大値
vector<int>dp;
int rec(int v){
  if(dp[v] != -1) return dp[v];

  int res = 0; 
  for (int i = 0; i < G[v].size(); i++)
  {
    chmax(res, rec(G[v][i])+1);
  }
  
  return dp[v] = res;
}



int main(){
  int n, m; cin >> n >> m;
  G.resize(n);
  for (int i = 0; i < m; i++)
  {
    int a, b; cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
  }
  int res = 0;
  dp.assign(n, -1);
  for (int i = 0; i < n; i++)
  {
    // dp初期化
    // dp.assign(n, -1);
    chmax(res, rec(i));
    // for(auto v: dp){
    //   cout << v << " ";
    // }
    // cout << endl;
  }
  cout << res << endl;



  return 0;
}