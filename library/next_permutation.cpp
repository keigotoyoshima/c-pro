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


// int main(){
//   int n = 5;
//   vector<int> v(n);
//   // 第3引数は、v[0]の値
//   iota(v.begin(), v.end(), 1);  

//   do{
//       for(int i=0; i<n; i++){
//         cout << v[i] << " ";
//       }
//       cout << endl;
//     }while(next_permutation(v.begin(),v.end()));
//   return 0;
// }

// 1 2 3 4 5
// 1 2 3 5 4
// 1 2 4 3 5
// 1 2 4 5 3
// 1 2 5 3 4
// 1 2 5 4 3
// 1 3 2 4 5
// 1 3 2 5 4
// 1 3 4 2 5
// 1 3 4 5 2
// 1 3 5 2 4
// 1 3 5 4 2
// 1 4 2 3 5
// 1 4 2 5 3 .....

int main()
{
  vector<int> v = {0, 1, 1};

  do
  {
    for (int i = 0; i < 3; i++)
    {
      cout << v[i] << " ";
    }
    cout << endl;
  } while (next_permutation(v.begin(), v.end()));
  return 0;
}

// 0 1 1 
// 1 0 1 
// 1 1 0 