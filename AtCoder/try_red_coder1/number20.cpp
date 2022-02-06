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





// 計算量n*lognの2条?
int main(){
  ll n; cin >> n;
  vector<ll>a(n);
  vector<ll>b(n);
  vector<ll>c(n);

  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (ll i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  for (ll i = 0; i < n; i++)
  {
    cin >> c[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    ll tem = b[i];
    // 下部
    ll index1 = upper_bound(c.begin(),c.end(),tem) - c.begin();
    ll bottom = n - index1;
    // 上部
    ll index2 = lower_bound(a.begin(),a.end(),tem) - a.begin();
    ll top = index2;
    ll plus = top*bottom;
    res += plus;
  }
  cout << res << endl;
  return 0;
}
// 上部から選定していくと、下部を選定する際に上部を変数として定まる中部をもとにする必要が出る。
// これは、明らかに下部が偏に定めることができない
// そこで、中部を第一変数とする。