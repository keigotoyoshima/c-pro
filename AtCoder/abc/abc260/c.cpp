#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
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

ll N, X, Y;

ll r[13];
ll b[13];
// 再帰関数での解法
ll rec(ll level, ll is_red){
  if(level == 1) return is_red ? 0 : 1;
  if(is_red){
    if(r[level] != -1) return r[level];
    return r[level] = rec(level-1, true) + rec(level, false) * X;
  }else{
    if(b[level] != -1) return b[level];
    return b[level] = rec(level-1, true) + rec(level-1, false) * Y;
  }
}

int main(){
  cin >> N >> X >> Y;
  memset(r,-1,sizeof(r));
  memset(b,-1,sizeof(b));
  ll blue = rec(N, true);
  cout << blue << endl;
  return 0;
}