#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
#include <math.h>
#include <numeric>
using namespace std;	
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<ll,ll>> ab(n);
  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> ab[i].first >> ab[i].second;
    res += ab[i].first;
  }


  vector<int>v(n);
  iota(v.begin(), v.end(), 0);
  sort(v.begin(), v.end(), [&](int i, int j){
    return 2*ab[i].first + ab[i].second > 2*ab[j].first + ab[j].second;
  });
  int cur = 0;
  int cnt = 0;
  while (res >= 0)
  {
    int i = v[cur];
    res -= (2*ab[i].first+ab[i].second);
    ++cur;
    ++cnt;
  }
  
  cout << cnt << endl;
    
  return 0;
}