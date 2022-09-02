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
  ll n,m,t;
  cin >> n >> m >>t;
  vector<ll>A(n-1);
  for(auto &n: A) cin >> n;
  map<ll,ll>mp;
  for (int i = 0; i < m; i++)
  {
    ll x,y; cin >> x >> y;
    x--;
    mp[x] = y;
  }

  bool flag = true;
  for (int i = 0; i < n-1 && flag; i++)
  {
    ll a = A[i];
    t -= a;
    if(t <= 0) flag = false;
    t += mp[i+1];
  }
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return 0;
}