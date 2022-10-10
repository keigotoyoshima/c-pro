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


int main(){
  ll n, m; cin >> n >> m;
  vector<ll>A(n);
  vector<ll>cum(n+1);
  for(auto &v : A) cin >> v;
  for(int i = 0; i < n; i++){
    cum[i+1] = cum[i] + A[i];
  }
  ll sum = 0;
  for(int i = 1; i <= m; i++){
    sum += A[i-1]*i;
  }
  ll ans = sum;

  for(int i = 0; i < n-m; i++){
    ll tem = sum;
    int r = i+m;
    int l = i;
    ll minus = cum[r] - cum[l];
    tem -= minus;
    tem += A[r] * m;
    sum = tem;

    ans = max(ans, sum);
  }
  
  cout << ans << endl;
  return 0;
}