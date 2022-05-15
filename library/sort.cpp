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

vector<pair<int, int>> sort1(vector<pair<int, int>> &V)
{
  sort(V.begin(), V.end(), [&](auto l, auto r) {
    if(l.first == r.first){
      return l.second > r.second;
    }else{
      return l.first < r.first;
    }
  });
  return V;
}



// pair-vectorに対するsort
vector<pair<int, int>> pair_list;


int main()
{
  pair_list.push_back(make_pair(2, 3));
  pair_list.push_back(make_pair(2, 4));
  pair_list.push_back(make_pair(2, 1));
  pair_list.push_back(make_pair(3, 3));
  pair_list.push_back(make_pair(1, 3));
  pair_list.push_back(make_pair(10, 1));
  for (int i = 0; i < pair_list.size(); i++)
  {
    cout << pair_list[i].first << " " << pair_list[i].second << endl;
  }
  sort(pair_list.begin(), pair_list.end());
  cout << "-------" << endl;
  sort1(pair_list);
  for (int i = 0; i < pair_list.size(); i++)
  {
    cout << pair_list[i].first << " " << pair_list[i].second << endl;
  }
}

// 2 3
// 2 4
// 2 1
// 3 3
// 1 3
// 10 1
// -------
// 1 3
// 2 4
// 2 3
// 2 1
// 3 3
// 10 1