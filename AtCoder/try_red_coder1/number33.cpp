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

int h,w;
vector<int>dx={0,0,-1,1};
vector<int>dy={1,-1,0,0};

bool judge(int nx, int ny){
  if(nx >= w || nx < 0 || ny >= h || ny < 0) return false;
  return true;
}


int main(){
  cin >> h >> w;
  vector<string>a(h);
  vector<vector<int>>ans(h,vector<int>(w,0));
  int cnt = 0;
  for (int i = 0; i < h; i++)
  {
    cin >> a[i];
    for (int j = 0; j < w; j++)
    {
      if(a[i][j] == '.') cnt++;
    }
    
  }
  queue<pair<int,int>>que;
  que.push(make_pair(0,0));
  bool flag = false;
  while (!que.empty() && !flag)
  {
    mpair v = que.front();
    int x = v.first;
    int y = v.second;
    que.pop();
    int nx,ny;
    for (int d = 0; d < 4; d++)
    {
      nx = x+dx[d];
      ny = y+dy[d];

      if(!judge(nx,ny) || a[ny][nx] == '#' || ans[ny][nx] > 0) continue;
      ans[ny][nx] = ans[y][x] + 1;
      if(ny == h-1 && nx == w-1){
        flag = true;
        break;
      }
      que.push(make_pair(nx,ny));
    }

  }

  if(flag) {
    cout << cnt - (ans[h-1][w-1] + 1) << endl;
  }else{
    cout << -1 << endl;
  }



  return 0;
  
}