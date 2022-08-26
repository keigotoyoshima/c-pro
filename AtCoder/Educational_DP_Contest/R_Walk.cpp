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


int n;
// 繰り返し二乗法
vector<vector<ll>> modPow(vector<vector<ll>>a, ll k)
{
  vector<vector<ll>> res(n, vector<ll>(n, 0));
  vector<vector<ll>> tem;

  if (k == 1){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        a[i][j] %= MOD;
      }
    }
    return a;
  }
   
  if (k % 2 == 1){
    tem = modPow(a, k - 1);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        for (int g = 0; g < n; g++)
        {
          res[i][j] += (a[i][g] * tem[g][j]) % MOD;
          res[i][j] %= MOD;
        }
      }
    }
    return res;
  }
   

  tem = modPow(a, k / 2);
 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int g = 0; g < n; g++){
        res[i][j] += (tem[i][g] * tem[g][j]) % MOD;
        res[i][j] %= MOD;
      }
    }
  }

  return res;
}

// 行列累乗
int main(){ 
  ll k;
  cin >> n >> k;
  vector<vector<ll>>A(n, vector<ll>(n,0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> A[i][j];
    }
  }
  vector<vector<ll>> res = modPow(A, k);
  ll ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans += (res[i][j] % MOD);
      ans %= MOD;
    }
  }
  cout << ans << endl;

  return 0;
}