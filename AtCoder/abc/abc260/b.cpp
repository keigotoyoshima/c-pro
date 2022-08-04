#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <string>
#include <assert.h>
#include <functional>
using namespace std;
using ll = long long;
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<int> k;

void fun(vector<ll>a, int x, int n){
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  sort(v.begin(), v.end(), [&](auto l, auto r){ 
    if(a[l] != a[r]) return a[l] > a[r]; 
    return l < r;
  });
  // for(auto nv: v) cout << nv << " ";
  // cout << endl;
  int index = 0;
  while (x)
  {
    if(a.size() == index) break;
    if (k[v[index]] != 1){
      // k[v[index]] = true;
      k[v[index]] = 1;
      --x;
    }
    index++;
  }
}


int main(){
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<ll>a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  k.resize(n);
  for(auto &v: a){
    cin >> v;
  }
  for(auto &v: b){
    cin >> v;
  }
  for(int i = 0; i < n; i++){
    c[i] = a[i] + b[i];
  }
  fun(a,x,n);
  fun(b,y,n);
  fun(c,z,n);

  for(int i = 0 ; i < n; i++){
    if(k[i] == 1) cout << i + 1 << endl;
  }
  

  return 0;
}