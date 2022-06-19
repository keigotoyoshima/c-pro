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





int main(){
  int h1,h2,h3,w1,w2,w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
  ll ans = 0;
  for (int a = 1; a <= h1-2; a++)
  {
    for (int b = 1; b <= h1-a-1; b++) 
    {
      int c = h1-a-b;
      for (int d = 1; d <= w1-a-1&& d <= h2-2; d++)
      {
        for (int e = 1; e <= w2-b-1 && e <= h2-d-1; e++)
        {
          int f = h2 - d - e;
          for (int g = w1-a-d; g <= w1-a-d && g <= h3-2; g++)
          {
            for (int h = w2-b-e; h <= w2-b-e && h <= h3-g-1; h++)
            {
              int i = h3-g-h;
              int r = w3-c-f;
              if(i != r)  continue;
              // cout << a << " " << b << " " << c << endl;
              // cout << d << " " << e << " " << f << endl;
              // cout << g << " " << h << " " << i << endl;
              // cout << endl;
              ans++;
            }
            
          }
          
        }
        
      }
      
    }
    
  }
  cout << ans << endl;
  
  return 0;
}