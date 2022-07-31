  #include <iostream>
  #include <vector>
  #include <cstdlib>
  #include <map>
  #include <set>
  #include <algorithm>
  #include <numeric>
  #include <queue>
  #include <cmath>
  #include <iomanip>
  #include <math.h>
  #include <string>
  #include <assert.h>
  using namespace std;
  using ll = long long;
  #define fi first
  #define se second
  template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
  template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
  const long long INF = 1LL << 60;
  int inf_int = 2147483647;
  const int MOD = 1000000007;
  const int dx[] = {-1, 0, 1, 0};
  const int dy[] = {0, 1, 0, -1};
  const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

  ll dp[410][410];
  vector<ll>a;
  vector<ll>cum;
  int n;
  ll ans = 0;

  // dp[l][r] = lからrまでのスライムを全ての通りで切った時の最小のコスト
  // 計算量は状態数がO(N2)、遷移がO(N)だから計算量は O(N3)

  ll rec(int l, int r, int c){
    if(dp[l][r] != -1) return dp[l][r];
    // cout << l << " : " << r << " : " << c << endl;
    if(l==r) return 0;
    ll res = INF;
    for(int i = l; i < r; i++){
      ll tem = rec(l,i,c-1) + rec(i+1, r, c-1);
      res = min(res, tem);
    }

    return dp[l][r] = res + (cum[r+1]-cum[l]);
  }

  int main(){
    cin >> n;
    a.resize(n);
    cum.resize(n+1);
    for(auto &v: a) cin >> v;
    for(int i = 0; i < 410 ; i++){
      for(int j = 0; j < 410; j++){
        dp[i][j] = -1;
      }
    }

    for(int i = 0; i < n; i++){
      cum[i+1] = cum[i] + a[i];
    }

    ll res = rec(0,n-1,10);
    // cout << endl;
    // for(int i = 0; i < 4; i++){
    //   for(int j = 0; j < 4; j++){
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    cout << res << endl;
    return 0;
  }