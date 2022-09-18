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




// counter clock wise
// clock wise = 時計回り
// counter clock wise = 反時計回り

struct V
{
  int x, y;
  V(int x=0, int y=0): x(x), y(y) {};
  V operator-(const V &z){
    return V(z.x-x, z.y-y);
  }
  int cross(const V &z){
    return  x*z.y - y*z.x;
  }
  int ccw(const V &z){
    int value = cross(z);
    if (value > 0)
      return 1;
    if (value < 0)
      return -1;
    return 0; // collinear
  }
};


int main(){
  vector<V>p(4);
  for (int i = 0; i < 4; i++)
  {
    cin >> p[i].x >> p[i].y;
  }
  for (int i = 0; i < 4; i++)
  {
    V A = p[i];
    V B = p[(i+1)%4];
    V C = p[(i+2)%4];
    V a = A-B; V c = C-B;
    if(c.ccw(a) <= 0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}