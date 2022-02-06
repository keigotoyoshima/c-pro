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


int main(){
  ll n, d; cin >> n >> d;
  using P = pair<ll, ll>;
  vector<P>v(n);
  for (int i = 0; i < n; i++)
  {
    ll l,r; cin >> l >> r;
    v[i].first = l;
    v[i].second = r;
  }
  sort(v.begin(),v.end(),[&](P lv, P rv){return lv.second < rv.second;});
  ll dist = 0;
  ll cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if(dist >= v[i].first) continue;
    ++ cnt;
    dist = v[i].second + d - 1;
  }
  
  cout << cnt << endl;

  
}