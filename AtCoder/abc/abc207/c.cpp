#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int>l(n),r(n);

  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t >> l[i] >> r[i];
    l[i] *= 2;
    r[i] *= 2;
    if(t%2 == 0){
      r[i] --;
    }
    if(t >= 3){
      l[i] ++;
    }
  }

  int ans = 0;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if(r[i] < l[j]) continue;
      if(l[i] > r[j]) continue;
      ans ++;
    }
  }

  cout << ans << endl;
  
  

  return 0;
}