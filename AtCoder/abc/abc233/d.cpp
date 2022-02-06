#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf = 1e6;

int main(){
  ll n, k; cin >> n >> k;
  vector<ll>a(n);
  vector<ll>s(n+1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    s[i+1] = a[i] + s[i];
  }
  map<ll,ll>mp;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    mp[s[i-1]]++;
    ans += mp[s[i] - k];
  }
  cout << ans << endl;
  return 0;
}