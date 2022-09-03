#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
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





int main(){
  int n;
  ll P, Q, R;
  cin >> n;
  cin >> P >> Q >> R;
  vector<int>A(n);
  for(auto &v : A) cin >> v;
  vector<ll>S(n+1);
  for (int i = 0; i < n; i++)
  {
    S[i+1] = S[i] + A[i];
  }
  for (int i = 0; i < n - 2; i++)
  {
    int x = i;
    ll value_x = S[x];
    ll find = P+value_x;
    auto y = lower_bound(S.begin(), S.end(), find) - S.begin();
    if(y == n || S[y] != find) {
      continue;
    }
    ll value_y = S[y];
    find = Q+value_y;
    int z = lower_bound(S.begin(), S.end(), find) - S.begin();
    if (z == n || S[z] != find){
      continue;
    }
    ll value_z = S[z];
    find = R+value_z;
    int w = lower_bound(S.begin(), S.end(), find) - S.begin(); 
    if (w == n || S[w] != find)
    {
      continue;
    }
    else
    {
      cout << "Yes" << endl;
      return 0;
    }

  }
  cout << "No" << endl;

  return 0;
}