#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
const ll mod=1000000007;

ll powmod(int k,int n){
  ll res = 1;
  for(int i = 0; i < n; i++){
    res = res*k%mod;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  ll ans = powmod(10,n) - powmod(9,n) - powmod(9,n) + powmod(8,n);
  
  ans %= mod;
  //ansが負の数になっている可能性を考慮
  ans=(ans+mod)%mod;

  cout << ans << endl;
  
  return 0;
}
