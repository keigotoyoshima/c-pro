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
const int dp[N][5];

int main(){
  int n;
  vector<int>T(n);
  map<int, bool>mp;
  vector<int>X(n);
  vector<ll>A(n);
  for (int i = 0; i < n; i++)
  {
    int t;
    int x;
    ll a;
    cin >> t >> x >> a;
    T[i] = t;
    mp[t] = true;
    X[i] = x;
    A[i] = a;
  }

  for (int i = 1; i < N + 1; i++)
  {
    auto itr = mp[i];
    bool flag = true;
    int t,x,a;
    if(itr == mp.end()){
      flag = false;
      a = 0;
    }else{
      t = i;
      x = X[i];
      a = A[i];
    }
    dp[i][j] = dp[i-1][j];
    if(flag){
      for (int j = 0; j < 5; j++)
      {
        if(j == x){
          if (j != 0)
            chmax(dp[i + t][k], dp[i][j - 1] + a);
          if (j != 4)
            chmax(dp[i + t][j], dp[i][j + 1] + a);
        }
      }
      
    }{
      for (int j = 0; j < 5; j++)
      {
        if (j != 0)
          chmax(dp[i + t][k], dp[i][j - 1]);
        if (j != 4)
          chmax(dp[i + t][j], dp[i][j + 1]);
      }
    }

  }

  
  

  
  return 0;
}