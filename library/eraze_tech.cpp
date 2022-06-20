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
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

// erazeで配列の中身を消すときに，erase(first, last)を使った場合, 中の要素をそれぞれスライドさせる必要があるため，O(N)かかってしまう．
// そこで，消したい要素を最後の要素とswapした後に，最後の要素を消すという処理で高速化できる，ただ，元々の順番を変えてしまうので注意が必要．
int main()
{
  vector<int> v{3, 1, 4, 1, 5};
  swap(v[0], v[4]);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  // 5 1 4 1 3

  // v.erase(v.begin() + 2);ではなく
  swap(v[2], v[v.size()-1]);
  v.pop_back();
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  // 5 1 3 1

  return 0;
}