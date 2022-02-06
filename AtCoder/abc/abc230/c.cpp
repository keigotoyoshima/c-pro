#include <algorithm>
#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
using ll = long long;


int main(){
  ll n, a, b; cin >> n >> a >> b;
  ll plus = a + b;
  ll minus = a - b;
  ll p,q,r,s; cin >> p >> q >> r >> s;

  ll w = s-r+1;
  ll h = q-p+1;
  vector<string>ans(h, string(w, '.'));

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      ll x = i+p; ll y = j+r;
      if(x + y == plus || x - y == minus) ans[i][j] = '#';
    }
  }

  
  for (int i = 0; i < h; i++)
  {
    cout << ans[i] << endl;
  }
  
  

  return 0;
} 

