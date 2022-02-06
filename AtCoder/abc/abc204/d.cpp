#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
#include <bitset>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
using ll = long long;
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define rep(i,a,b) for(int i=a;i<b;i++)
// const int inf = 1e6;
// int dp[101][102010];



int main(){
  int n; cin >> n;

  bitset<10010>dp;
  // オーブンAの時間をdpの添字とし、部分和が成り立つ場合は、1に設定する。
  dp[0] = 1;
  int total = 0;
  for (int i = 0; i < n; i++)
  {
    int t; cin >> t;
    total += t;
    dp |= dp << t;
  }

  int ans = total;
  for (int i = 0; i < total + 1; i++)
  {
    if(dp[i]) ans = min(ans, max(i, total - i));
  }

  
  
  cout << ans  << endl;

}