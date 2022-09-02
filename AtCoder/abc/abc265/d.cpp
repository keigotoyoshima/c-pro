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
  vector<int>A(n-1);
  for(auto &v : A) cin >> v;
  vector<ll>S(n);
  for (int i = 0; i < n-1; i++)
  {
    S[i+1] = S[i] + A[i];
  }
  for (int i = 0; i <= n; i++)
  {
    int x = i;
    ll value_x = S[x];
    int y = lower_bound(S.begin(), S.end(), P + value_x) - S.begin();
    while (1)
    {
      if(S[y] != P + value_x) {
        break;
      }
      ll value_y = S[y];
      int z = lower_bound(S.begin(), S.end(), Q+value_y) - S.begin();
      while (1)
      {
        if (S[z] != Q + value_y){
          break;
        }
        ll value_z = S[z];
        int w = lower_bound(S.begin(), S.end(), R+value_z) - S.begin(); 

        while (1)
        {
          if (S[w] != R + value_z)
          {
            break;
          }
          else
          {
            cout << "Yes" << endl;
            return 0;
          }
          w++;
        }
        z++; 
      }
      y++;
    }
  }
  cout << "No" << endl;

  return 0;
}