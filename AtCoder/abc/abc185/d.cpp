#include <algorithm>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
using ll = long long;


// int main(){
//   ll n,  m;
//   cin >> n >> m;
//   vector<ll>a(m);
//   for (int i = 0; i < m; i++)
//   {
//     cin >> a[i];
//     --a[i];
//   }
//   sort(a.begin(), a.end());

//   vector<ll>v;
//   a.insert(a.begin(), -1);
//   a.push_back(n);  
//   ll k = n;
//   // for(auto k: a){
//   //   cout << k << endl;
//   // }
//   // cout << endl;
//   for (int i = 1; i <= a.size(); i++)
//   {
//     ll len = a[i+1] - a[i] - 1;
//     if(len > 0){
//       v.push_back(len);
//       k = min(k, len);
//     } 
//     // cout << i << " " << a[i] << endl;
//   }
//   // cout << "a[a.size()] " << a[a.size()] << endl;

//   ll ans = 0;
  
//   for(auto len: v){
//     ans += (len + k - 1)/k;
//   }
  
  
//   cout << ans << endl;
//   return 0;
// } 


int main(){
  ll n, m;
  cin >> n >> m;
  vector<ll>a(m);
  for (ll i = 0; i < m; i++)
  {
    cin >> a[i];
    a[i] --;
  }


  sort(a.begin(), a.end());
  a.push_back(n);
  a.insert(a.begin(), -1);

  
  vector<ll>len;
  ll minest = n;
  for (ll i = 1; i < a.size(); i++)
  {
    ll k = a[i] - a[i-1] - 1;
    if(k > 0){
      len.push_back(k);
      minest = min(k, minest);
    }
  }
  

  ll res = 0;
  for(auto v: len){
    res += (v + minest -1)/ minest;
  }
  cout << res << endl;
  return 0;

  
}