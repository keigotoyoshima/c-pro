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
  string s; cin >> s;
  ll k; cin >> k;
  ll n = s.size();
  // 連番
  vector<ll> v(n);
  // 第3引数は、v[0]の値
  iota(v.begin(), v.end(), 0);
  vector<string>st;
  do
  {
    string tem;
    for (int i = 0; i < n; i++)
    {
      tem.push_back(s[v[i]]);
    }
    st.push_back(tem);
  } while (next_permutation(v.begin(), v.end()));

  // 辞書順にソート
  sort(st.begin(),st.end(), [&](string l, string r){
    for (int i = 0; i < n; i++)
    {
      if(l[i] != r[i]){
        return l[i] - 'a' < r[i] - 'a';
      }
    } 
    return l < r;
  }
  );


  st.erase(unique(st.begin(), st.end()), st.end());


  cout << st[k-1] << endl;
  
  return 0;
}