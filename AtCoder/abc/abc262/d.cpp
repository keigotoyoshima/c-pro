// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <map>
// #include <set>
// #include <algorithm>
// #include <numeric>
// #include <queue>
// #include <deque>
// #include <cmath>
// #include <iomanip>
// #include <math.h>
// #include <string>
// #include <assert.h>
// #include <functional>
// using namespace std;
// using ll = long long;
// #define fi first
// #define se second
// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// const long long INF = 1LL << 60;
// int inf_int = 2147483647;
// const int MOD = 998244353;
// const int dx[] = {-1, 0, 1, 0};
// const int dy[] = {0, 1, 0, -1};
// const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
// const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

// int n;
// vector<int>a;
// int dp[110][MOD];
// // k == 現在のindex, s == 合計値,
// int rec(int k, int s){
//   cout << k << " : " << s << endl;
//   if(k == -1) {
//     if(s % n == 0)  {
//       dp[0][s] = 1;
//       return dp[0][s] %= MOD;  
//     }else{
//       return dp[0][s] = 0;
//     }
//   }
//   if(dp[k][s] != -1) return dp[k][s];
//   int k1 = rec(k-1, s);
//   int k2 = rec(k-1, s + a[k]);

//   return dp[k][s] = k1 + k2;
// }

// // dp[i][j][k]=i番目まででj個選んで、選んだ数の和をnで割ったあまりがkになる方法の数
// int main(){
//   cin >> n;
//   a.resize(n);
//   for(auto &v: a) cin >> v;
//   for(int i = 0; i < 110; i++){
//     for(int j = 0; j < 10; j++){
//       dp[i][j] = -1;
//     }
//   }

//   int ans = rec(n-1, 0);
//   cout << endl;
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < n; j++){
//       cout << dp[i][j] << " " ;
//     }
//     cout << endl;
//   }
//   cout << endl;

//   cout << ans << endl;
//   return 0;
// }