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
using P = pair<int, int>;


// 幅優先とダイクストラを使って解く問題
// https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_e

vector<int> edge[108000];
ll dist[108000];
bool zombie[108000];
bool danger[108000];
int pcost, qcost;
int n, m, k, s, x, a, b;

void dijkstra(int start)
{
  // <頂点番号>
  priority_queue<int, vector<int>, greater<int>> pq;
  fill(dist, dist + 108000, INF);

  dist[start] = 0;
  pq.push(start);

  while (!pq.empty())
  {
    int from = pq.top();
    pq.pop();

    for (int i = 0; i < edge[from].size(); i++)
    {
      int to = edge[from][i];
      // この問題特有---
      if (zombie[to]) continue;
      int cost = pcost;
      if (danger[to])cost = qcost;
      if (to == n)cost = 0;
      // -------------
      if (dist[to] > dist[from] + cost)
      {
        dist[to] = dist[from] + cost;
        pq.push(to);
      }
    }
  }
}

int main()
{

  cin >> n >> m >> k >> s;
  cin >> pcost >> qcost;

  // ゾンビの街
  queue<int> q;

  for (int i = 0; i < k; i++)
  {
    cin >> x;
    zombie[x] = true;
    q.push(x);
  }

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  for (int i = 0; i <= s; i++)
  {
    if (q.empty()) break;

    for (int j = q.size() - 1; j >= 0; j--)
    {
      int from = q.front();
      q.pop();
      if (danger[from]) continue;
      danger[from] = true;
      for (int k = 0; k < edge[from].size(); k++)
      {
        q.push(edge[from][k]);
      }
    }
  }

  dijkstra(1);

  cout << dist[n] << endl;

  return 0;
}