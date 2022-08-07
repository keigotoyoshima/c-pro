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





int main(){
  int n; cin >> n;
  vector<int>p(n);
  p[0] = -1;
  for(int i = 0; i < n-1; i++){
    int tem ; cin >> tem;
    p[i+1] = tem - 1;
  }

  int cnt = 0;
  int check = p[n-1];
  for(int i = n-1; i >= 0; i--){
    if(i == check){
      cnt++;
      check = p[i];
    } 
  }

  cout << cnt << endl;
  return 0;
}