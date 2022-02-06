#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;


int main() {
  int n; cin >> n;
  vector<vector<pair<int,int>>>v(n);
  for (int i = 0; i < n; i++)
  {
    int a; cin >> a;
    for (int j = 0; j < a; j++)
    {
      int x, y; cin >> x >> y;
      x--;
      v[i].push_back(make_pair(x,y));
    }
  }
  int res = 0;
  for (int bit = 0; bit < (1<<n); bit++)
  {
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
      if(bit>>i & 1) {
        cnt ++;
        for (int j = 0; j < v[i].size(); j++)
        {
          if((bit>>v[i][j].first & 1) && (v[i][j].second == 0)) flag = true;
          if(!(bit>>v[i][j].first & 1) && (v[i][j].second == 1)) flag = true;
        }
        if(flag) break;
      }
    }
    if(!flag) res = max(res, cnt);
  }
  cout << res << endl;
  
  
  
}

