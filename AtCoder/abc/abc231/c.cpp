#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) {  if (a > b) { a = b; return 1; } return 0; }

const long long INFL = 1LL << 60;
const int inf = 1e6;


int main(){
  int n, q;  cin >> n >> q;
  vector<int>a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  for (int i = 0; i < q; i++)
  {
    int x; cin >> x;
    int ng = -1; int ok = n;
    while (ok - ng > 1)
    {
      int md = (ng + ok) / 2;
      if (a[md] >= x) ok = md;
      else ng = md;
    }
    cout << n - ok << endl;
    
  }
  
  
  return 0;
}