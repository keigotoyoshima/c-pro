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
  int n ; cin  >> n;
  vector<vector<int>>A(n);
  for (int i = 0; i < n; i++)
  {
    string input; cin >> input;
    for (int j = 0; j < input.size(); j++)
    {
      A[i].push_back(input[j]-'0');
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int si = i; int sj = j;
      for (int k = 0; k < 8; k++)
      {
        ll V = 0;
        for (int p = 0; p < n; p++)
        {
          V = V*10 + A[si][sj];
          si += dx8[k];
          sj += dy8[k];
          si = (si+n)%n;
          sj = (sj+n)%n;
        }
        chmax(ans, V);
      }
      
    }
  }

  cout << ans << endl;
  
  return 0;
}