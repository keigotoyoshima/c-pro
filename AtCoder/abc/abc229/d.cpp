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

string s;
vector<ll> cum;
ll k;

// 二分探索と累積和を使った解法
// start=始点のindex
bool isOK(int start,int mid) {
  int key = cum[mid] - cum[start];
  if (k >= key) return true;
  else return false;
}
int binary_search(int start) {
  int ok = start;
  int ng = s.size()+1;

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (isOK(start,mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}
int main(){
  cin >> s;
  int n = s.size();
  cum.resize(n+1);
  cin >> k; 
  int ans_len = 0;
  vector<int>a(n);
  for (int i = 0; i < n; ++i) cum[i+1] = cum[i] + (s[i] == '.' ? 1:0);
  for (int i = 0; i < n; i++)
  { 
    int ok_index = binary_search(i);
    int tem = ok_index - i;
    chmax(ans_len, tem);
  }
  cout << ans_len << endl;
  return 0;
}
// 尺取り法を使った解法
// int main() {
//   string s;
//   int k;
//   cin >> s >> k;
//   int n = s.size();
//   vector<int> a(n);
//   for (int i = 0; i < n; i++)
//   {
//     a[i] = s[i] == '.';
//   }
  
//   rep(i,n) a[i] = s[i]=='.';
 
//   int ans = 0;
//   int r = 0, sum = 0;
//   for (int l = 0; l < n; l++)
//   {
//     while (r < n && sum+a[r] <= k) {
//       sum += a[r];
//       ++r;
//     }
//     ans = max(ans, r-l);
//     sum -= a[l];
//   }

 
//   cout << ans << endl;
//   return 0;
// }