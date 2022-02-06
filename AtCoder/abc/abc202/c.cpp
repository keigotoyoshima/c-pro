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
  int n;
  cin >> n;
  vector<int> b(n), c(n);
  map<int, int> mp_a;    
  map<int, int> mp_d;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    mp_a[a] ++;
  }
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++)
  {
    int d = b[--c[i]];
    mp_d[d] ++;
  }

  ll ans = 0;

  for(auto itr_a = mp_a.begin(); itr_a != mp_a.end(); ++itr_a) {
    int first_a = itr_a->first;
    auto itr_d = mp_d.find(first_a);       
    if( itr_d != mp_d.end() ) {
        // 設定されている場合の処理
        ll second_a = itr_a->second;
        ll second_d = itr_d->second;
        ans += second_a*second_d; 
    } 
  }


  cout << ans << endl;

    

  
 

  
  
  return 0;
}
