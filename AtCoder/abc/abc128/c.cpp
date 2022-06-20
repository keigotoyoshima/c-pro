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

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m);
  vector<int> p(m);
  for (int i = 0; i < m; i++)
  {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
      int s;
      cin >> s;
      s--;
      a[i].push_back(s);
    }
  }
  for (int i = 0; i < m; i++)
  {
    cin >> p[i];
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++)
  {
    set<int> st;
    for (int i = 0; i < n; i++)
    {
      if (bit & (1 << i))
      {
        st.insert(i);
      }
    }
    vector<int> data(m);
    for (int o = 0; o < m; o++)
    {
      for(auto v: a[o]){
        if (st.find(v) != st.end())
          data[o]++;
      }
    }
    bool flag = true;
    for (int j = 0; j < m; j++)
    {
      if (p[j] != data[j]%2){
        flag = false;
      }
        
    }
    if(flag) ans ++;
  }

  cout << ans << endl;
  return 0;
}

// int main() {
//   int n, m;
//   cin >> n >> m;
//   vector<vector<int>> s(m);
//   vector<int>p(m);

//   for (int i = 0; i < m; i++)
//   { 
//     int k;
//     cin >> k;
//     for (int j = 0; j < k; j++)
//     {
//       int sw;
//       cin >> sw;
//       --sw;
//       s[i].push_back(sw);
//     } 
//   }

//   for (int i = 0; i < m; i++)
//   {
//     cin >> p[i];
//   }

//   int ans = 0;
  
//   for (int bit = 0; bit < (1<<n); bit++)
//   {
//     bool flag = true;
//     for (int i = 0; i < m; i++)
//     {
//       int cnt = 0;
//       for(auto v: s[i]) {
//         if(bit & (1<<v)) ++cnt;
//       }
//       if(cnt % 2 != p[i]) flag = false;
//     }
//     if(flag)  ++ans;
    
//   }
//   cout << ans << endl;

//   return 0;
// }
