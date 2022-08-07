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
#include <functional>
using namespace std;
using ll = long long;
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int MOD = 998244353;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
// n=1,2,3...に対して
// dp[i][j][k] = i-1番目まででj個選んで、選んだ数の和をnで割ったあまりがkになる方法の数 
ll n;
vector<ll>a;
int dp[101][100][100];

void init(){
  for(int i = 0; i < 101; i++){
    for(int j = 0; j < 100; j++){
       for(int k = 0; k < 100; k++){
          dp[i][j][k] = 0;
     }
   }
  }
}

int solve(ll cnt){
  init();
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {

      for (int k = 0; k < cnt; k++)
      {
        // dp[i][j][k] = 0;
        // cout << "row " <<  cnt << " " << j << " " << k << endl;
        int tem = (cnt + k - a[i - 1] % cnt) % cnt;
        // cout << k << " " << tem << endl;
        if (j > 0){ 
          dp[i][j][k] += dp[i - 1][j - 1][tem] % MOD;
          // cout << "yes" << endl; 
        }

        // cout << dp[i][j][k] << endl;
        dp[i][j][k] += dp[i - 1][j][k] % MOD;
        // cout << dp[i-1][j][k] << endl;
        // cout << dp[i][j][k] << endl;
      }
    }
  }

  // cout << "cnt: " << cnt << endl;
  // cout << dp[n][cnt][0] << endl;

  // cout << endl;
  // for(int i = 0; i < 5; i++){
  //   for(int j = 0; j < 5; j++){
  //      for(int k = 0; k < 5; k++){
  //         cout << dp[i][j][k] << ' ';
  //    }
  //    cout << endl;
  //  }
  //  cout << endl;
  // }
  // cout << endl;
  return dp[n][cnt][0];
}

int main()
{
  cin >> n;
  a.resize(n);
  for(auto &v: a) cin >> v;
  ll sum = 0;
  for(int i = 1; i <= n; i++){
    sum += solve(i)%MOD;
  }
  cout << sum << endl;

  // cout << endl;
  // for(int i = 0; i < 5; i++){
  //   for(int j = 0; j < 5; j++){
  //      for(int k = 0; k < 5; k++){
  //         cout << dp[i][j][k] << ' ';
  //    }
  //    cout << endl;
  //  }
  //  cout << endl;
  // }
  // cout << endl;



  return 0;
}