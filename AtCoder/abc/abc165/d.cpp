#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll f(ll x, ll A, ll B) { return (A * x) / B - A * (x / B); }
int main() {
  ll a, b, n;
  cin >> a >> b >> n; 
  ll ans = 0;
  ll x = b-1;
  if(n < b) x = n;
  ans = f(x, a, b);
  
  cout << ans << endl;
}