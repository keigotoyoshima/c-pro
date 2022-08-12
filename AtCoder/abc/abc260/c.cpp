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

int N, X, Y;

// blueの数を返す
ll rec(int level, int is_red){
  if(level == 1) return is_red ? 0 : 1;
  if(is_red){
    return rec(level - 1, true) + rec(level, false) * X;
  }else{
    return rec(level - 1, true) + rec(level - 1, false) * Y;
  }
}

int main(){
  cin >> N >> X >> Y;
  ll blue = rec(N, true);
  cout << blue << endl;
  return 0;
}