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


// bfS使う解法
// int main(){
//   int n ; cin >> n;
//   vector<ll>x(n);
//   vector<ll>y(n);
//   vector<ll>p(n);
//   for (int i = 0; i < n; i++)
//   {
//     cin >> x[i] >> y[i] >> p[i];
//   }
//   ll ok = 4e9;
//   ll ng = -1;
//   while (abs(ok - ng) > 1){
//     ll mid = (ok + ng) / 2;
//     // s＝midの時,全てのジャンプ台を経由できるか判定
//     bool flag = [&]{
//       vector<vector<ll>>d(n,vector<ll>(n,-1));
//       // 全てのジャンプ台の組み合わせの有効グラフを作成
//       for (int i = 0; i < n; i++)
//       {
//         ll xi = x[i];
//         ll yi = y[i];
//         ll psx = mid * p[i];
//         for (int j = 0; j < n; j++)
//         {
//           ll xj = x[j];
//           ll yj = y[j];
//           if(psx >= abs(xi-xj) + abs(yi-yj)) d[i][j] = 1;
//         }
//       }

//       // bfs
//       for (int start = 0; start < n; start++)
//       {
//         vector<ll> dist(n, -1);
//         queue<ll> que;
//         dist[start] = 0;
//         que.push(start);
//         while (!que.empty())
//         {
//           ll v = que.front();
//           que.pop();
//           for (int i = 0; i < n; i++)
//           {
//             ll value = d[v][i];
//             ll nv = i;
//             if (value == -1)
//               continue;
//             if (dist[nv] != -1)
//               continue;
//             dist[nv] = dist[v] + 1;
//             que.push(nv);
//           }
//         }

//         bool tem_flag = true;
//         for (auto v : dist)
//         {
//           if(v==-1) tem_flag = false;
//         }
//         if(tem_flag) return true;
//       }
//       return false;
//     }();
//     if (flag)
//     {
//       ok = mid;
//     }
//     else
//     {
//       ng = mid;
//     }
//   }
  
//   cout << ok << endl;
//   return 0;
// }


// ワーシャルフロイド法使う解法
int main()
{
  int n;
  cin >> n;
  vector<ll> x(n);
  vector<ll> y(n);
  vector<ll> p(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i] >> p[i];
  }
  ll ok = 4e9;
  ll ng = -1;
  while (abs(ok - ng) > 1)
  {
    ll mid = (ok + ng) / 2;
    // s＝midの時,全てのジャンプ台を経由できるか判定
    bool flag = [&]
    {
      vector<vector<ll>> dp(n, vector<ll>(n, 0));
      // 全てのジャンプ台の組み合わせの有効グラフを作成
      for (int i = 0; i < n; i++)
      {
        ll xi = x[i];
        ll yi = y[i];
        ll psx = mid * p[i];
        for (int j = 0; j < n; j++)
        {
          ll xj = x[j];
          ll yj = y[j];
          if (psx >= abs(xi - xj) + abs(yi - yj)) dp[i][j] = 1;
        }
      }

      // ワーシャルフロイド
      for (int k = 0; k < n; k++)
      { // 経由する頂点
        for (int i = 0; i < n; i++)
        { // 始点
          for (int j = 0; j < n; j++)
          { // 終点
            // dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            dp[i][j] |= dp[i][k]&dp[k][j];
          }
        }
      }

      for (int i = 0; i < n; i++)
      {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
          if(dp[i][j] != 1) flag = false;
        }
        if(flag) return true;
      }
      return false;
    }();
    if (flag)
    {
      ok = mid;
    }
    else
    {
      ng = mid;
    }
  }

  cout << ok << endl;
  return 0;
}