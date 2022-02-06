#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll k, n; cin >> n >> k;
  vector<pair<ll,ll>>ab;
  for (int i = 0; i < n; i++)
  {
    ll a, b;cin >> a >> b;
    ab.push_back({a,b});
  }
  sort(ab.begin(), ab.end());
  for (int i = 0; i < n ; i++)
  {
    if(ab[i].first > k) break;
    k += ab[i].second;
  }
  
  cout << k << endl;

  


  return 0;
}
