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

int main(){
  int n,q; cin >> n >> q;
  vector<ll>a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  map<ll,vector<ll>>mp;
  // 要素名．順番
  for (int i = 0; i < n; i++)
  {
    mp[a[i]].push_back(i);
  }
  
  for (int i = 0; i < q; i++)
  {
    ll x,k; cin >> x >> k;
    auto itr = mp.find(x);
    if (itr != mp.end())
    {
      if(mp[x].size() < k){
        cout << -1 << endl;
      }else{
        cout << mp[x][k - 1] + 1 << endl;
      }
    }
    else
    {
      cout << -1 << endl;
    }
  }
  return 0;
  
}