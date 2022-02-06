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
  vector<int>p(n);
  vector<int>q(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> q[i];
  }
  


  vector<int> v(n);
  // 第3引数は、v[0]の値
  iota(v.begin(), v.end(), 1);  
  int cnt = 0;
  int a,b;
  do{
    cnt ++;
    if(v == p) a = cnt;
    if(v == q) b = cnt;
    }while(next_permutation(v.begin(),v.end()));

  cout << abs(a-b) << endl;
  return 0;
}

// 特になし