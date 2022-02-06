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

ll n; 
vector<int>h;
vector<int>s;
bool isOK(ll mid) {
  // midは決めうちされた最高の高さ

  // midを通過するまでにかかる時間、通過したらfalse
  vector<ll>t(n);

// 包括される可能性があったとしても明らかな除外事項は実装しといた方がいい
  for (int i = 0; i < n; i++)
  {
    if(h[i] > mid) return false;
  }
  
  for (int i = 0; i < n; i++)
  {
    ll time = (mid-h[i])/s[i];
    t[i] = time;
  }
  sort(t.begin(), t.end());
  for (int i = 0; i < n; i++)
  {
    if(t[i] < i)  return false;
  }
  return true;
  
}


ll binary_search(ll key) {
    ll ng = -1;  
    ll ok = key;

    while (abs(ok - ng) > 1) {  
        ll mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}
// 計算量はlog(max(hi+si*n))nlong(n)
int main(){
  cin >> n;
  h.resize(n);
  s.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
    cin >> s[i];
  }

  ll x = binary_search(inf_ll);
  cout << x << endl;
  return 0;



}
// どの風船をどの順番で割るべきかが判断つかない。
// 順列全探索では、計算量が間に合わない。
// そこで、最大の高さ（x）を二分探索で決め打ちしていき、成り立つ場合とそうでない場合を判別する。
// 判別方法は、xに到達するための時間でsortして、n個の風船を１秒ずつ割った場合に、全ての風船が、時間内に割ることができるかで判別する。
// 包括される可能性があったとしても明らかな除外事項は実装しといた方がいい
