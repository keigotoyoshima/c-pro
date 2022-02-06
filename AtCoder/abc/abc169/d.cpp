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


// 素因数分解は O(N‾‾√) で実現できる。
// 素因数分解
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {  
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
  ll n; cin >> n;
  auto pf = prime_factorize(n);

  int res = 0;
  for(auto x : pf){
    int e = x.second;
    int cur = 1;
    int tem = 0;
    while (cur <= e)
    {
      e -= cur;
      ++cur;
      ++tem;
    }
    res += tem;
  }

  cout << res << endl;
}
