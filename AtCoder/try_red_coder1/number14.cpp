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
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf_ll = 1e15;
int inf_int = 2147483647;


int main(){
  ll n,k; cin >> n >> k;
  vector<ll>a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  ll ans = infl;
  for (int bit = 0; bit < (1<<n); ++bit)
  {
    ll cost = 0;

    ll max_x = a[0];
    ll cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (bit & (1<<i)) { 
          cnt++;
        }
    }
    if(cnt != k-1) continue;



    for (int i = 1; i < n; ++i) {
        if (bit & (1<<i)) { 
          if(max_x >= a[i]){
            cost += max_x + 1 - a[i];
            max_x++;
          }
        }
        max_x = max(max_x, a[i]);
    }

    ans = min(ans, cost);
    
  }

  cout << ans << endl;
  return 0;
}

// infをllversionに設定する。
// bit全探索で見えるようにする建物を決めうち。k個の時のみなのでそれ以外は、continue;
// コストを計算して、最小を出力。
// コスト計算の際には、それまでの最大の建物の高さを更新していく。