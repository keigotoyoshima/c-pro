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



// dp[l][r]=[l,r]の区間が残っている時の[直前の人の得点-その前の人の得点]

ll dp[3100][3100];
bool flag[3100][3100];
vector<ll>a;
ll f(int l, int r, int c){
  if(flag[l][r]) return dp[l][r];
  flag[l][r] = true;
  if(l == r) return dp[l][r] = a[l];
  ll left = a[l] - f(l+1,r,1);
  ll right =  a[r] - f(l, r-1, 2);  
  dp[l][r] = max(left, right);
  // cout << l << " : "  << r << " : " << c <<  endl;
  return dp[l][r];
}

int main(){
  int n; cin >> n;
  a.resize(n);
  for(auto &v: a) cin >> v;
  for(int i = 0; i < 3100; ++i){
    for(int j = 0; j < 3100; ++j){
      dp[i][j] = false;
    }
  }

  ll ans = f(0, n-1, 1);
  cout << ans << endl;
  return 0;
}