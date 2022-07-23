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
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  bool both = false;
  bool flag1 = false;
  bool flag2 = false;
  int ans = 0;
  for (int i = 0; i <= 100; i++)
  {
    if (l1 <= i &&  i < r1)
    {
      flag1 = true;
    }else{
      flag1 = false;
    }
    if (l2 <= i && i < r2)
    {
      flag2 = true;
    }else{
      flag2 = false;
    }

    if(flag1 && flag2){
      ans ++;
    }
  }
  cout << ans  << endl;
  
  return 0;
}