#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
#include <math.h>
using namespace std;	
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> v(110000,0);
   ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    int k; cin >> k;
    ans += k;
    ++v[k];
  }
  int q; cin >> q;
 
  for (int i = 0; i < q; i++)
  {
    ll b, c; cin >> b >> c;
    ans += (c - b)*v[b];
    v[c] += v[b];
    v[b] = 0;
    cout << ans << endl;
  }
  
  return 0;
}