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
  vector<int>a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ans = 0;
  vector<int>record(4, 0);
  for (int i = 0; i < n; i++)
  {
    record[0] ++;
    int tem = a[i];
    vector<int>tem_record(4,0);
    for (int j = 0; j < 4; j++)
    {
      if(record[j] != 0){
        record[j]--;
        int k = j + tem;
        if(k > 3) {
          ans ++;
        }else{
          tem_record[k]++;
        }
      }
    }
    // for (int p = 0; p < tem_record.size(); p++)
    // {
    //   cout << tem_record[p] <<  " ";
    // }
    // cout << endl;
    record = tem_record;
    
  }
  cout << ans << endl;
  
  return 0;
}