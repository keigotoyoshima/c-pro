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
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

// idとvalueの一対多の関係のデータ保持方法を考えてみた．
// 下記の方法では少なくとも，全id要素個数分の配列容量のみの容量で済んだ．

int main()
{
  int n; cin >> n;
  // 実際の値を二次元配列に保持
  vector<vector<int>> v;
  // vのindexを保持(つまり，id->index) pair(index, indexの進行状況)
  map<int, pair<int,int>> mp;

  for (int i = 0; i < n; i++)
  {
    int id;
    cin >> id;
    int value;
    cin >> value;
    if (mp.find(id) != mp.end())
    {
      v[mp[id].first].push_back(value);
      --i;
      --n;
    }
    else
    {
      mp[id] = make_pair(i,0);
      vector<int>insertV={value};
      v.push_back(insertV);
      // v[i].push_back(value);
      
    }
  }
  // 入力
  // 4
  // 4 19
  // 3 4 
  // 4 2
  // 1 3

  cout << "n " << n << endl;
  // 3
  cout << "v.size() " << v.size() << endl;
  // 3

  cout << "mp" << endl;
  for (auto itr = mp.begin(); itr != mp.end(); ++itr)
  {
    int a = itr->first;
    pair<int,int> b = itr->second;
    cout << a << " " << b.first << endl;
  }
// 1 2
// 3 1
// 4 0

  cout << "v" << endl;
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << " " ;
    }
    cout << endl;
  }
  // 19 2 
  // 4 
  // 3 
  cout << endl;

  // idに対するvalueを一つづつ使いたい時
  pair<int,int>p = mp[4];
  cout << v[p.first][p.second] << endl;
  // 19
  mp[4].second ++;
  p = mp[4];
  cout << v[p.first][p.second] << endl;
  // 2

  return 0;
}