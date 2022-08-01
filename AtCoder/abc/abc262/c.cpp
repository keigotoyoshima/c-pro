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


int main(){
  ll n; cin >> n;
  vector<ll>a(n+1);
  for(int i = 0; i < n; i++){
    cin >> a[i+1];
  }


  ll cnt_a = 0;
  ll cnt_b = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] == i){
      cnt_a++;
    }else{
      if(i == a[a[i]] && a[i] > i) cnt_b++;
    }
  }

 ll ans = 0;
 if(cnt_a > 1) {
  //  ans = nCk(cnt_a, 2);
    ans = cnt_a * (cnt_a - 1) / 2;
  }

  ans += cnt_b ;






  cout << ans << endl;
   
  return 0;
}