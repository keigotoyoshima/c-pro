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
  int n; cin >> n;
  ll m; cin >> m;
  vector<ll>a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  a.push_back(0);
  sort(a.begin(),a.end());
  ll res = 0;
  vector<ll> q;
  for (int e = 0; e < n+1; e++)
  {
    for (int f = 0; f < n+1; f++)
    {
      ll tem = a[e] + a[f];
      q.push_back(tem);
      // auto itr = find(q.begin(), q.end(), tem);   
      // if( itr == q.end() ) {     
      //   q.push_back(tem);
      // }
      
    }
    
  }

  sort(q.begin(),q.end());

  for (int i = 0; i < q.size(); i++)  
  {
    ll p = q[i];
    if(p > m) continue;
    ll rest = m - p;

    ll index = upper_bound(q.begin(), q.end(), rest) - q.begin();
    ll tem = p + q[index-1];


    res = max(res, tem);

  }
  
  cout << res << endl;
  return 0;
  
}

// N<=300なので、得点の組み合わせを全探索だと間に合わない。そこで、あらかじめ得点０を追加(ダーツを打たないことと同義)しといて、2本打った場合の得点をO(N^2)で求めて、sortしておく(N^2log(n))。そうすることで、残りの2本をM以下になるように選定。（log(n))
// 結果、全体の計算量は(N^2log(n))で収まる。