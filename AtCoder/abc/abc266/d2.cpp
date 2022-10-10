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


const int N = 110000;
ll dp[N][5];

// 配るDPで実装+解答参考
int main(){
  int n; cin >> n;
  vector<int>X(N);
  vector<ll>A(N);
  for (int i = 0; i < n; i++)
  {
    int t; cin >> t;
    cin >> X[t] >> A[t];
  }
  for (int i = 0; i < N; i++){
    for(int j = 0; j < 5; j++){
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < 5; j++){
      for(int nj = j-1; nj <= j+1; nj++){
        if(nj < 0 || 4 < nj) continue;
        chmax(dp[i+1][nj], dp[i][j]);
      }
    }
    dp[i+1][X[i+1]] += A[i+1];
  }
  ll ans = 0;
  for(int i = 0; i < 5; i++){
    ans = max(ans, dp[N-1][i]);
  }
  cout << ans <<  endl;
  
  return 0;
}