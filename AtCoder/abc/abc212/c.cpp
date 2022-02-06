#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n, m; cin >> n >> m;
  vector<ll>a(n);
  vector<ll>b(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll res = 1e9;
  int x = 0;
  int y = 0;
  while(n > x && m > y){
    res = min(res, abs(a[x]-b[y]));
    if(a[x] >= b[y]){
      ++y;
    }else{
      ++x;
    }
  }
 
  
  cout << res << endl;

  return 0;
}
