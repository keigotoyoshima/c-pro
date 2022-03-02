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

const ll mod = 998244353;
int main()
{
  string s; cin >> s;
  ll keta = 0;
  ll p = atoi(s.c_str());
  while (p)
  {
    p /= 10;
    keta++;
  }
  vector<ll>a;

  for (int i = 0; i < keta; i++)
  {
    a.push_back(s[i] - '0');
  }
  reverse(a.begin(), a.end());
  for(auto v: a){
    cout << v << " ";
  }
  cout << endl;
  // cout << keta << endl;

  ll cnt = 0;
  ll len;
  // 前の桁数までの数値
  ll pre_num;
  ll ans = 0;
  ll tem = 0;
  for (int i = 0; i < keta; i++)
  { 
    // po := 今の桁数の数値
    ll po = a[i] * pow(10, i);
    cout << "po " <<  po << endl;
    // tem := 今の桁数までの数値
    tem += po;
    cout << "tem " << tem << endl;
    ll max_l = po - pow(10,i);
    cout << "max_l " << max_l << endl;

    // 初項a,末項l, 項数n;
    ll a,l,n; 
    if(i == 0){
      a = 1;
      l = tem;
      n = tem;
    }else{
      a = 1;
      l = tem;
      n = max_l + pre_num + 1;
    }
    ll plus = (a+l)*n/2;
    cout << "plus " << plus << endl;
    ans += plus;
    pre_num = tem;
  }
  cout << ans << endl;

  return 0;
}