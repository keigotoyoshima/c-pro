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

const int N = 1e5+100;
ll dp[N][2];
vector<int>a[N];
bool flag[N];

void bfs(int v = 1, int from = -1){
  flag[v] = true;
  dp[v][0] = 1;
  dp[v][1] = 1;
  for(auto to: a[v]){
    if(to == from) continue;
    bfs(to, v);
    dp[v][0] *= (dp[to][0] + dp[to][1])%MOD;
    dp[v][0] %= MOD;
    dp[v][1] *= dp[to][0];
    dp[v][1] %= MOD;
  }
}

int main(){
  int n; cin >> n;
  // a.resize(n);
  memset(flag, false, sizeof(flag));
  for(int i = 0; i < n-1; i++){
    int x,y; cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  bfs();
  cout << (dp[1][0]+dp[1][1])%MOD << endl;

  return 0;
}