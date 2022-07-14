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





int main(){
  int n; cin >> n;
  vector<vector<int>>data(n);
  vector<int> a(n);
  vector<int> d(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++)
  {
    int a, b, c; cin >> a >> b >> c;
    data[i].push_back(a);
    data[i].push_back(b);
    data[i].push_back(c);
    // cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<ll>>dp(n + 1,vector<ll>(3,0));
  dp[0][0] = data[0][0];
  dp[0][1] = data[0][1];
  dp[0][2] = data[0][2];

  for (int i = 0; i < n-1; i++)
  {

    // j=配る側のabc
    for (int j = 0; j < 3; j++)
    {
      // k=貰う側のabc
      for (int k = 0; k < 3; k++)
      {
        if(j==k) continue;
        chmax(dp[i+1][k], (ll)dp[i][j] + data[i+1][k]);
      }  
    } 
  }

  ll ans = 0;
  for (int i = 0; i < 3; i++)
  {
    chmax(ans, (ll)dp[n-1][i]);
  }

  // for(auto v: )

  cout << ans << endl;
  


  

  return 0;
}