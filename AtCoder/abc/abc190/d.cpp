#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INFL = 1LL << 60;
const int inf = 1e6;


vector<pair<ll, ll> > prime_factorize(ll n) {
  vector<pair<ll, ll> > res;
  for (ll p = 2; p * p <= n; ++p) {
      if (n % p != 0) continue;
      int num = 0;
      while (n % p == 0) { ++num; n /= p; }
      res.push_back(make_pair(p, num));
  }
  if (n != 1) res.push_back(make_pair(n, 1));
  return res;
}

int main(){
  ll n; cin >> n;
  ll m = n;
  while (m%2 == 0)
  {
    m /= 2;
  }
  
  vector<pair<ll, ll>> res; 
  res = prime_factorize(m);
  ll cnt = 1;
  for (int i = 0; i < res.size(); i++)
  {
    cnt *= res[i].second+1;
  }
  cout << cnt * 2 << endl;


  return 0;
}