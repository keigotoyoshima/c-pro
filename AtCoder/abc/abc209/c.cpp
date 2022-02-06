#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  ll n;
  cin >> n;
  vector<ll>v(n);
  const ll mod = 1e9 + 7;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  ll ans = 1;
  
  for (int i = 0; i < v.size(); i++)
  {
    ans = (ans * (v[i] - i)) % mod;
  }
  cout << ans << endl;
  
  return 0;
}