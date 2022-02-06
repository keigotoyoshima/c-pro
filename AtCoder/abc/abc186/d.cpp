#include <algorithm>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
using ll = long long;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  
  // 累積和
  vector<ll> s(n+1, 0);
  for (int i = 0; i < n; ++i) s[i+1] = s[i] + a[i];
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += (a[i]*i) - (s[i]);
  }
  
  cout << ans << endl;

  return 0;
} 

