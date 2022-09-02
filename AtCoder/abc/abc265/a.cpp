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


int n;
int solve(int yen, int amount){
  int consume = n/amount;
  return yen * consume;
}

int main(){
  int x, y;
  cin >> x >> y;
  cin >> n;
  int plan_a = solve(x,1);
  int plan_b = solve(y,3);
  n %= 3;
  if(n == 0){
    
  }else if(n == 1){
    plan_b += x;
  }else if(n == 2){
    plan_b += 2*x;
  }
  int ans = min(plan_a, plan_b);;
  cout << ans << endl;
  return 0;
}