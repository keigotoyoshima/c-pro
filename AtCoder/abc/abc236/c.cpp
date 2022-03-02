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

int main()
{
  // string s = "abc";
  // string b = "abc";
  // string d = "abcd";
  // if(s==b) cout <<"yes1" << endl;
  // if(d==b) cout <<"yes2" << endl;
  int n,m; cin >> n >> m;
  vector<string>a(n);
  vector<string> b(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  map<string, int> mp;
  for (int i = 0; i < m; i++)
  {
   mp[b[i]] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    string tem = a[i];
    if(mp[tem]){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }

  return 0;
  
  

  return 0;
}