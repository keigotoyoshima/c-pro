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
  ll n;
  cin >> n;
  map<int, ll> mp;  
  int a;
  for(int i = 0; i < n; i++){
    cin >> a;
    mp[a]++;
  }
  ll ans = n*(n-1)/2;
  for(auto&[a,b]:mp){
    ans-=b*(b-1)/2;
  }
  cout << ans << endl;

  return 0;
}