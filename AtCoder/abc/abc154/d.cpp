#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
#include <limits>
#include <iomanip>
using namespace std;

using Graph = vector<vector<int>>;
using ll = long long;

int main() {
  int n, k; cin >> n >> k;
  vector<ll>v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    ++v[i];
  }

  // 累積和
  vector<ll> s(n+1, 0);
  for (int i = 0; i < n; ++i) s[i+1] = s[i] + v[i];

  ll res = 0;
  for (int i = 0; i + k <= n; i++)
  {
    res = max(res, s[i+k] - s[i]);
  }
  

  cout << fixed << setprecision(10) << (double)res/2 << endl;
}