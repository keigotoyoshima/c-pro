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
#include <iomanip>
#include <math.h>
#include <string>
#include <assert.h>
#include <functional>
using namespace std;
using ll = long long;
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};



// 頭の中で樹形図思い描けば理解できた．
// s==現在のindex
void recursive_comb(int *indexes, int s, int rest, function<void(int *)> f)
{
  if (rest == 0)
  {
    cnt++;
    f(indexes);
  }
  else
  {
    if (s < 0)
      return;
    // sを使わない場合
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    // sを使う場合
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, function<void(int *)> f)
{
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main()
{
  // f=組み合わせ列挙関数(indexesに組み合わせが入ってくる)
  foreach_comb(5, 3, [](int *indexes)
               { std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl; });
  
  cout << cnt << endl;
}
// 0,1,2
// 0,1,3
// 0,2,3
// 1,2,3
// 0,1,4
// 0,2,4
// 1,2,4
// 0,3,4
// 1,3,4
// 2,3,4

// ll nCk(int n, int k)
// {
//   ll x = 1; 
//   ll y = 1; 
//   ll z = 1;

//   for (int i = 0; i < n; i++)
//     x *= n - i;
//   for (int i = 0; i < n-k; i++)
//     y *= n - k - i;
//   for (int i = 0; i < k; i++)
//     z *= k - i;
//   return (x / (y * z)); 
// }