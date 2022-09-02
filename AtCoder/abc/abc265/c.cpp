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


vector<vector<char>>G;
vector<vector<bool>> memo;
const int u[] = {-1,0};
const int d[] = {1, 0};
const int l[] = {0, -1};
const int r[] = {0,  1};

int h, w;

bool judge(int i, int j){
  bool flag = true;
  if (i >= h || i <= -1 || j >= w || j <= -1)
    flag = false;

  return flag;
}

int main(){
  cin >> h >> w;
  G.resize(h, vector<char>(w,'1'));
  memo.resize(h, vector<bool>(w, false));
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
  while(flag){
    char tem = G[i][j];
    if(memo[i][j]){
      roop = true;
      break;
    }
    memo[i][j] = true;
    int next_i = i;
    int next_j = j;
    if (tem == 'U')
    {
      next_i += u[0];
      next_j += u[1];
      if(judge(next_i,next_j)){
        i += u[0];
        j += u[1];
      }else{
        break;
      }
    }
    else if (tem == 'D')
    {
      next_i += d[0];
      next_j += d[1];
      if(judge(next_i,next_j)){
        i += d[0];
        j += d[1];
      }else{
        break;
      }
    }
    else if (tem == 'L')
    {
      next_i += l[0];
      next_j += l[1];
      if(judge(next_i,next_j)){
        i += l[0];
        j += l[1];
      }else{
        break;
      }
    }
    else if (tem == 'R')
    {
      next_i += r[0];
      next_j += r[1];
      if(judge(next_i,next_j)){
        i += r[0];
        j += r[1];
      }else{
        break;
      }
    }
    
  }

  if(roop){
    cout << -1 << endl;
  }else{
    cout << i + 1 << " " << j + 1 << endl;
  }


  return 0;
}