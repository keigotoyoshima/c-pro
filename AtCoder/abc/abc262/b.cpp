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
#include <iomanip>
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
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};





int main(){
  int n,m ; cin >> n >> m;
  vector<vector<int>> G(n, vector<int>(n,-1));

  for(int i = 0; i < m; i++){
    int u, m; cin >> u >> m;
    --u; --m;
    G[u][m] = 1;
    G[m][u] = 1;
  }
  int ans = 0;
  for(int a = 0; a < n; a++){
    for(int b = a ; b < n; b++){
      for(int c = b; c < n;  c++){
        int route_a = G[a][b];
        int route_b = G[b][c];
        int route_c = G[c][a];
        if(route_a == 1 && route_b == 1 && route_c == 1) ans ++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}