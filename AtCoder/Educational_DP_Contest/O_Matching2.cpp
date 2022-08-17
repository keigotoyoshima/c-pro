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



void addmod(int &x, int y){
  x += y;
  x %= MOD;
}

int dp[(1<<21)];

int main(){
  int n;
  cin >> n;
  vector<vector<int>>a(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  dp[0] = 1;
  for(int S = 1; S < (1<<n); S ++){
    int cur = __builtin_popcount(S);
    for(int i = 0; i < n; i++){
      if((S&(1<<i)) && a[cur-1][i] == 1){
        addmod(dp[S], dp[S^(1<<i)]);
      }
    }
  }
  cout << dp[(1<<n)-1] << endl;

  return 0;
}