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
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};





using P = pair<ll,ll>;

int main(){
  int n; cin >> n;
  P S;
  P T;
  ll sx, sy;
  cin >> sx >> sy;
  S=make_pair(sx, sy);
  ll tx, ty;
  cin >> tx >> ty;
  T=make_pair(tx,ty);
  vector<P>XY(n);
  vector<ll>R(n);
  for (int i = 0; i < n; i++)
  {
    cin >> XY[i].fi >> XY[i].se >> R[i];
  }

  auto pow2 = [=](ll x){return x*x;};
  auto dist = [=](P a, P b){
    return pow2(a.fi-b.fi) + pow2(a.se-b.se);
  };
  // S,Tがどの円なのか
  int s_index = inf_int;
  int t_index = inf_int;
  for (int i = 0; i < n; i++)
  {
   ll r = R[i];
   if (pow2(r) == dist(S,XY[i])) s_index = i;
  
   if (pow2(r) == dist(T,XY[i])) t_index = i;
   
   if(s_index != inf_int && t_index != inf_int) break;
  }

  // 有効グラフ作成
  vector<vector<int>>dp(n,vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  { 
    for (int j = 0; j < n; j++)
    {
      ll dif = abs(R[i] - R[j]);
      ll plus = R[i] + R[j];
      ll disy = XY[i].se - XY[j].se;
      ll disx = XY[i].fi - XY[j].fi;
      ll dis = disy*disy + disx*disx;
      if(pow2(dif) <= dis && dis <= pow2(plus)) {
        dp[i][j] = 1;
      }
    }
  }


  vector<int> dist_bfs(n, -1);
  queue<int> que;
  dist_bfs[s_index] = 0;
  que.push(s_index);
  while (!que.empty())
  {
    int v = que.front();
    que.pop();
    
    for (int i = 0; i < n; i++)
    {
      ll value = dp[v][i];
      ll nv = i;
      if (value == 0)
        continue;
      if (dist_bfs[nv] != -1)
        continue;
      dist_bfs[nv] = dist_bfs[v] + 1;
      que.push(nv);
    }
  }


  if(dist_bfs[t_index] != -1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}