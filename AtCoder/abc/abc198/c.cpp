#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
#include <math.h>
using namespace std;
using ll = long long;

int main(){
 ll r, x , y;
  cin >> r >> x >> y;

  ll d2 = x*x + y*y;
  ll ans =  1;
  while (1)
  {
    if(r*r*ans*ans >= d2) break;
    ans ++;
  }
  // r*r < d2とするとWA
  if(ans == 1){
    if(r*r > d2) ans = 2;
  }

  cout << ans << endl;
  return 0;
}
