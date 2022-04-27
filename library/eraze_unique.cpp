

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
#include <math.h>
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
const ll inf_ll = 1e15;
int inf_int = 2147483647;
using mpair = pair<int, int>;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

// int main()
// {
//   std::vector<int> vec = {10, 40, 40, 20, 20, 30, 20, 20, 40};
//   std::unique(vec.begin(), vec.end());
//   printVec(vec); // 10 40 20 30 20 40 ? ? ?
// }
// std::uniqueは隣接する重複要素を削除するが、
// vectorの長さなどには変更を加えないため、末尾にはゴミが残ることになる。

int main(){
  // std::uniqueはゴミの手前のポインタを返すので、vector::eraseで後ろのゴミを削除する。 これで重複要素のないvectorが得られる。
  vector<int> vec = {10, 40, 40, 20, 20, 30, 20, 20, 40};
  sort(vec.begin(), vec.end());
  cout << *vec.begin() << endl;
  cout << *vec.end() << endl;
  cout << *unique(vec.begin(), vec.end()) << endl;
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  // printVec(vec); // 10 20 30 40
}