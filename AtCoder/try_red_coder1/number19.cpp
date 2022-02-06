  #include <iostream>
  #include <vector>
  #include <cstdlib>
  #include <algorithm>
  #include <map>
  #include <set>
  #include <algorithm>
  #include <numeric>
  #include <queue>
  #include <cmath>
  #include<math.h>
  using namespace std;
  using ll = long long;
  template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
  template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
  const long long INFL = 1LL << 60;
  const ll inf_ll = 1e15;
  int inf_int = 2147483647;

  int main(){
    ll d; cin >> d;
    ll n; cin >> n;
    ll m; cin >> m;
    vector<ll>a;
    a.push_back(0);
    for (int i = 0; i < n-1; i++)
    {
      ll input; cin >> input;
      a.push_back(input);
    }
    sort(a.begin(), a.end());
    a.push_back(d);
    ll res = 0;
    for (int i = 0; i < m; i++)
    {
     ll dest; cin >> dest;
     ll index = lower_bound(a.begin(), a.end(), dest) - a.begin();
     ll l = abs(a[index]-dest);
     ll r  = abs(a[index-1]-dest);
     ll tem = min(l,r);
     res += tem;
    }
    cout << res << endl;
    return 0;
  }

  // lower_boundの使い方覚えた
  // ある点より大か小であることさえわかれば、境界点の比較で答えがわかる。