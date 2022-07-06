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





int main(){
  int n, x; cin >> n >> x;
  vector<int>a(n);
  vector<int>b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }
  ll ans = 2e18;
  ll minB = 1e18;
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i] + b[i];
    chmin(minB, (ll)b[i]);
    if(i + 1 > x) break;
    ll tem_ans = minB*(x-i-1) + sum;
    chmin(ans, tem_ans);
  }

  cout << ans << endl;
  
  return 0;
}