#include <algorithm>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  // 累積和
  vector<long long> cum(n+1, 0);
  for (int i = 0; i < n; ++i) cum[i+1] = cum[i] + a[i];

  return 0;
}