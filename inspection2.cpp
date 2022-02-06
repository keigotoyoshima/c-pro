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
const int inf = 1e6;
int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
 
  int ans = 0;
  int r = 0;  
  int tem = 0;
  for (int i = 0; i < n; i++)
  {  
    
    while (r < n && (tem+plus) <= k)
    {
      int plus = s[r]=='.'?1:0;
      tem+=plus;
      ++r;
    }
    int minus = s[i]=='.'?-1:0;
    tem+=minus;
    chmax(ans, r-i);
  }
  cout << ans << endl;
  return 0;
}
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