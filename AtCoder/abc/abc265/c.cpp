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



int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> G(h, vector<char>(w,'1'));
  vector<vector<bool>> memo(h, vector<bool>(w, false));

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> G[i][j];
    }
  }

  bool flag = true;
  bool roop = false;
  int i = 0; int j = 0;
  while(1){
    char tem = G[i][j];
    if(memo[i][j]){
      roop = true;
      break;
    }

    memo[i][j] = true;
    int ni = i;
    int nj = j;
    if (tem == 'U') ni --;
    if (tem == 'D') ni ++;
    if (tem == 'L') nj --;
    if (tem == 'R') nj ++;
    if (ni >= h || ni <= -1 || nj >= w || nj <= -1)
      flag = false;
    if(flag){
      i = ni;
      j = nj;
    }else{
      break;
    }
  }
  if (roop)
  {
    cout << -1 << endl;
  }else{
    cout << i + 1 << " " << j + 1 << endl;
  }


  return 0;
}