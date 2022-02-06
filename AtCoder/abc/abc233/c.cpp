#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf = 1e6;

// 深さ優先探索
// vector<bool> seen;
vector<vector<ll>>a;
ll n;
ll x;
ll ans = 0;
void dfs(ll v, ll sum) {
    // seen[v] = true; 
    for (auto next_v : a[v]) { 
      if(next_v > x/sum) continue;
      if(v == n-1){
        // cout << "v " << v << " sum " << sum << " next_v " << next_v << endl;
        if(sum*next_v == x){
          ++ ans;
        } 
        continue;
      }
      dfs(v+1, sum*next_v); 
    }
}


int main(){
  cin >> n >> x;
  a.resize(n);
  for (int i = 0; i < n; i++)
  {
    ll l; cin >> l;
    a[i].resize(l);
    for (int j = 0; j < l; j++)
    {
      cin >> a[i][j];
    }
  }
  dfs(0,1);
  cout << ans << endl;
  return 0;
}