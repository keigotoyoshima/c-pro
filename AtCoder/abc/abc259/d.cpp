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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};





int main(){
  int n; cin >> n;
  pair<ll,ll>S;
  pair<ll,ll>T;
  ll sx, sy;
  cin >> sx >> sy;
  S=make_pair(sx, sy);
  ll tx, ty;
  cin >> tx >> ty;
  T=make_pair(tx,ty);
  vector<ll>X(n);
  vector<ll>Y(n);
  vector<ll>R(n);
  for (int i = 0; i < n; i++)
  {
    cin >> X[i] >> Y[i] >> R[i];
  }
  // S,Tがどの円なのか
  int s_index = inf_int;
  int t_index = inf_int;
  for (int i = 0; i < n; i++)
  {
   ll x = X[i]; ll y = Y[i]; ll r = R[i];
   if (r * r == (S.first - x) * (S.first - x) + (S.second - y) * (S.second - y)){
     s_index = i;
   }
   if (r * r == (T.first - x) * (T.first - x) + (T.second - y) * (T.second - y))
   {
     t_index = i;
   }
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
      ll disy = Y[i] - Y[j];
      ll disx = X[i] - X[j];
      ll dis = disy*disy + disx*disx;
      if(dif*dif <= dis && dis <= plus*plus) {
        dp[i][j] = 1;
      }
    }
  }


  vector<int> dist(n, -1);
  queue<int> que;
  dist[s_index] = 0;
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
      if (dist[nv] != -1)
        continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }


  if(dist[t_index] != -1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}