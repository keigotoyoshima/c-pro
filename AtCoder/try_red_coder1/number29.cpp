#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
#include<math.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf_ll = 1e15;
int inf_int = 2147483647;
using mpair = pair<int,int>;


int main() {
  int r,c; cin >> r >> c;
  int sy,sx; cin >> sy >> sx;
  --sy;--sx;
  int gy,gx; cin >> gy >> gx;
  --gy;--gx;
  vector<string>a(r);
  vector<vector<int>>res(r,vector<int>(c,-1));
  for (int i = 0; i < r; ++i) {
    cin >> a[i];
  }

  queue<pair<int,int>> que;

  que.push(make_pair(sy,sx)); 
  res[sy][sx] = 0;
  vector<int>direction={-1,1};
  
  while (!que.empty()) {
      mpair v = que.front(); 
      int x = v.second;
      int y = v.first;
      que.pop();
      for (int i = 0; i < 2; i++)
      {
        for (int j = 0; j < 2; j++)
        {
          int plus_x = 0;
          int plus_y = 0;
          if(i == 0){
            plus_x = direction[j];
          }else{
            plus_y = direction[j];
          }

          int ny = y + plus_y;
          int nx = x + plus_x;

          if(a[ny][nx] == '#' || res[ny][nx] != -1) continue;
          res[ny][nx] = res[y][x] + 1;
          que.push(make_pair(ny,nx));
        }
      }

  }
  cout << res[gy][gx] << endl;
  return 0;
}

// 特になし．