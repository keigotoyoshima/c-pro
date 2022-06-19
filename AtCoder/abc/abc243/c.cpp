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
  int n; cin >> n;
  ll max = 1e9+1;
  map<ll,deque<pair<ll,int>> mp;
  map<ll,ll>index_mp;
  for (int i = 0; i < n; i++)
  {
    ll x,y; cin >> x >> y;
    mp[y].push_back(x);
    index_mp[i] = y;
  }
  string S; cin >> S;
  for (int i = 0; i < S.size(); i++)
  {
    char c = S[i];
    ll y = index_mp[i];
    if(c == 'R'){
      mp[y] = 1;
    }else{
      mp[y] = false;
    }
  }
  
  
  return 0;
}