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


int main()
{
  int n, q; cin >> n >> q;
  string s; cin >> s;

  int len = s.size()-1;

  int top = 0;
  
  for (int i = 0; i < q; i++)
  {
    int query, x; cin >> query >> x;
    if(query == 1){
      top = (top-x+n)%n;
    }else{
      cout << s[(top+x-1)%n] << endl;
    }
  }
  
 
  return 0;
}