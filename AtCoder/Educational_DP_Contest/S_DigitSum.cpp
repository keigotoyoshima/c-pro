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

ll dp[11000][2][100];

// 桁DP
int main(){
  string K; cin >> K;
  int N = K.size();
  int D; cin >> D;

  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    int tem = K[i] - '0';
    for (int f = 0; f < 2; f++)
    {
      for (int j = 0; j < D; j++)
      {
        int lim = f ? 10 : tem + 1;
        for (int k = 0; k < lim; k++)
        {
          dp[i + 1][f == 1 || k != tem][(j + k) % D] += dp[i][f][j];
          dp[i + 1][f == 1 || k != tem][(j + k) % D] %= MOD;
        }
      }
    }
    
  }

  cout << (dp[N][1][0] + dp[N][0][0] - 1 + MOD)%MOD << endl;

  return 0; 
}