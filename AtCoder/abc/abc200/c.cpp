#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int>m(200);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    m[a%200]++;
  }
  ll res = 0;
  for (int i = 0; i < 200; i++)
  {
    res += (ll)m[i]*(m[i]-1)/2;
  }
  cout << res << endl;
  
    

  


  return 0;
}
