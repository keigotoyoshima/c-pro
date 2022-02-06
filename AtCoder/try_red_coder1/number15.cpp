#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
#include<math.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf_ll = 1e15;
int inf_int = 2147483647;

int main(){
  int n; cin >> n;
  vector<int>x(n);
  vector<int>y(n);
  vector<int> v(n);

  iota(v.begin(), v.end(), 0); 
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
    cin >> y[i];
  }
  double ans = 0;

  int cnt = 0;
  do{
    cnt++;
    for(int i=1; i<n; i++){
      double a = x[v[i]] - x[v[i-1]];
      a = pow(a, 2);
      double b = y[v[i]] - y[v[i-1]];
      b = pow(b, 2);
      double tem = a + b;
      ans += sqrt(tem);
    }
    }while(next_permutation(v.begin(),v.end()));

  // cout << (double)ans/cnt << endl;
  printf("%.10f\n", ans/cnt);

  return 0;
}

// 出力時の小数点指定は,printf("%.10f\n", ans/cnt);を使う
