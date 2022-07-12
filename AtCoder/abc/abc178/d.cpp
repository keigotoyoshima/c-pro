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
const int mod = 1e9 + 7;


int main() {
  int S;
  cin >> S;
  vector<ll> dp(S+1, 0);
  dp[0] = 1;
  for (int v = 1; v <= S; ++v) {
    for (int d = 0; d <= v - 3; ++d){
      dp[v] += (dp[d])%mod;
    } 
  }
  // for (int i = 0; i <= S; i++)
  // {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;

  cout << dp[S]%mod << endl;
}



// 式変形
// int main()
// {
//   int s, a[2010];
//   cin >> s;
//   a[0] = 1, a[1] = a[2] = 0;
//   for (int i = 3; i <= s; i++)
//   { 
//     a[i] = (a[i - 1] + a[i - 3]) % mod;
//   }
//   cout << a[s] << endl;
// }
